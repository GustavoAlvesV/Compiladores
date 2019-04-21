//Definitions
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>  
#include "symbol_table.h"
#include "stack.h"
#define UNDEFINED_SYMBOL_ERROR -21	
#define TYPE_MISMATCH_ERROR -20

#define ERROR_UNDEFINED_SYMBOL(ref) printf("VARIAVEL %s NAO DECLARADA.\n", ref);return UNDEFINED_SYMBOL_ERROR;
#define ERROR_TYPE_MISMATCH() printf("ERROR DE TIPAGEM.\n");return TYPE_MISMATCH_ERROR;		


symbol_t stable;
stack pilha = NULL;
int deslocamento = 600;
int deslocamentorx = 0;
int base = 0;
FILE *fp, *fo;	
int yylex();
int yyerror(char *s);
int getTipo(int tipo);
%}

//Tokens

%token INT
%token DOUBLE
%token FLOAT
%token CHAR

%token ADD
%token SUB
%token MULT
%token DIV


%token QUOTE
%token DQUOTE 

%token LE
%token GE
%token EQ
%token NE

%token AND
%token OR
%token NOT
%token IF
%token THEN
%token ELSE
%token WHILE

%token BRANCO 
%token IDF
%token F_LIT
%token INT_LIT

%token TRUE
%token FALSE
%token END

%left ADD SUB
%left MULT DIV
%left OR
%left AND
%left NOT


%union{
	char *name; // PARA IDF
	struct type{
		int tipoinNum;
		int sizeTipo;
	}type;

	struct lit{
		char *valorinText;
		int sizeLit;
		double valorinNum;
	}lit;  // para INT E FLOAT

	struct var{
		char* literal;  // nome da variavel se for variavel
		double valorVar;   //valor da variavel, inicial = 0
	        int tipoVar;   	// tipo da variavel 
	        int size;    	//tamanho para aquele tipo
	        int desloc;   // posiçao da memoria que ela inicia
		void* codigo;
		int extra;   // se é idf ou unumm ou um RX
	}var;  // PARA ADM VARIAVEL 
}


%type<lit>  F_LIT
%type<lit>  INT_LIT

%type<name> IDF
%type<name> lista_IDF

%type<type> tipo
%type<type> tipos
%type<type> INT
%type<type> DOUBLE
%type<type> CHAR
%type<type> FLOAT

%type<var> lvalue
%type<var> expr


//Rules

%%
programa	:	declaracoes acoes
		|	acoes		
		;

// Declarações:

declaracoes	:	declaracao';' 
		|	declaracoes declaracao';'
		; 

declaracao 	:	lista_IDF':'tipos 
				{	
				 	char* var;
					entry_t* idf;
					while(!empty(pilha)){
						var = (char*) pop(&pilha);
						idf = malloc(sizeof(entry_t));
						idf->name = malloc(sizeof(char)*(strlen(var) + 1));
						strcpy(idf->name, var);
						idf->valor = 0;
						idf->type = $3.tipoinNum;
						idf->size = $3.sizeTipo;
						idf->desloc = deslocamento;
						deslocamento += idf->size;
						printf("%03d: %03d:%03d(SP) %s := tipo: %d \n", base, idf->desloc, deslocamento, var, idf->type);
						//base = base + 1;
						insert(&stable,idf);
						//print_table(stable);
					}

				}
		; 


lista_IDF	:	lista_IDF','IDF 
				{push(&pilha,$3);} 	
		|	IDF		
				{push(&pilha,$1);} 
		;
		

tipos 		:	tipo   {$$.tipoinNum = $1.tipoinNum; $$.sizeTipo = $1.sizeTipo; } 
		|	tipo'['lista_INT 
		;

	
tipo		:	INT    
		|	DOUBLE  
		|	FLOAT	
		|	CHAR	
		;

lista_INT	:	lista_INT','INT_LIT':'INT_LIT
		|	lista_INT']'
		|	INT_LIT':'INT_LIT



		;

// Ações:

acoes		: 	acoes';'comando 
		| 	comando		
		;

comando		: 	atrib 	
		| 	enun_simples
		;

atrib		: 	lvalue'='expr	
				{	
						fo = fopen("saida.txt","a");
						char* op;
						int auxTipo = verificaTipo(&$1, &$3);
						if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
						if($1.tipoVar != INT || $3.tipoVar != INT){op = malloc(sizeof(char)*(strlen("FMOVE") + 1));strcpy(op,"FMOVE");}
							else{op = malloc(sizeof(char)*(strlen("MOVE") + 1));strcpy(op,"MOVE");}

						if($3.extra == 0){  // = num
							fprintf(fo,"%03d: %03d(SP)  := %03d(SP) %s %.01f \n", base, $1.desloc, $1.desloc, op,  $3.valorVar);
						}
						else if($3.extra == 1){   // = idf
							fprintf(fo,"%03d: %03d(SP)  := %03d(SP) %s %03d(SP) \n", base, $1.desloc, $1.desloc, op, $3.desloc);
						}
						else{  // = rx
							fprintf(fo,"%03d: %03d(SP)  := %03d(SP) %s %03d(RX) \n", base, $1.desloc, $1.desloc, op, $3.desloc);
						}
						base++;
						if($1.tipoVar != INT || $3.tipoVar != INT){op = malloc(sizeof(char)*(strlen("FPRINTF") + 1));strcpy(op,"FPRINTF");}
							else{op = malloc(sizeof(char)*(strlen("PRINTF") + 1));strcpy(op,"PRINTF");}
						fprintf(fo,"%03d: %s = %03d(SP) \n", base, op, $1.desloc);
						base++;
						fclose(fo);
					}
		;

// Gramática:
	
lvalue 		: 	IDF			
						{
							entry_t* var = NULL;
							var = lookup(stable, $1);
							if(var == NULL){
								ERROR_UNDEFINED_SYMBOL($1);
							}
							else{
								$$.valorVar = var->valor;
							    	$$.literal = var->name;
								$$.desloc = var->desloc;
								$$.tipoVar = var->type;
								$$.size = var->size;
								$$.extra = 1;
								$$.codigo = NULL;
							}
						}

		| 	IDF'['lista_expr	{	}
		;

lista_expr	:	expr','lista_expr	{	}
		| 	expr']'			{	}
		;




expr		:	expr ADD expr		{	char *op;	
							int auxTipo = verificaTipo(&$1, &$3);
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							$$.tipoVar = auxTipo; $$.size = auxSize;
				
							if($1.tipoVar != INT || $3.tipoVar != INT){op = malloc(sizeof(char)*(strlen("FADD") + 1));strcpy(op,"FADD");}
							else{op = malloc(sizeof(char)*(strlen("ADD") + 1));strcpy(op,"ADD");}


							if($1.extra != 2 && $3.extra != 2){ // soma 2 idfs ou ints ou floats ou doubles // cria temporario pegando ultima endereço de memoria 
								$$.valorVar = $1.valorVar + $3.valorVar;
								$$.desloc = deslocamentorx;
								$$.extra = 2;  // a soma vira rx
								deslocamentorx += $$.size;   
							}	
							else if($1.extra == 2 && $3.extra != 2){    // se primeiro e uma rx   
								$$.valorVar = $1.valorVar + $3.valorVar;
								$$.desloc = $1.desloc;
								$$.extra = 2;
							}
							else if($1.extra != 2 && $3.extra == 2){    // se segundo e uma rx   
								$$.valorVar = $1.valorVar + $3.valorVar;
								$$.desloc = $3.desloc;
								$$.extra = 2;
							}
							else if($1.extra == 2 && $3.extra == 2){   // se os dois for rx
								if($1.tipoVar >= $3.tipoVar){
									$$.valorVar = $1.valorVar + $3.valorVar;
									$$.desloc = $1.desloc;
									$$.extra = 2;
								}
								else{
									$$.valorVar = $1.valorVar + $3.valorVar;
									$$.desloc = $3.desloc;
									$$.extra = 2;
								}
							}

							
							gera_Cod(&$1, &$3, &$$, op);
							base++;
						}


		| 	expr SUB expr		{	char *op;	
							int auxTipo = verificaTipo(&$1, &$3);
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							$$.tipoVar = auxTipo; $$.size = auxSize;
							
							if($1.tipoVar != INT || $3.tipoVar != INT){op = malloc(sizeof(char)*(strlen("FSUB") + 1));strcpy(op,"FSUB");}
							else{op = malloc(sizeof(char)*(strlen("SUB") + 1));strcpy(op,"SUB");}

							if($1.extra != 2 && $3.extra != 2){
								$$.valorVar = $1.valorVar - $3.valorVar;
								$$.desloc = deslocamentorx;
								$$.extra = 2;
								deslocamentorx += $$.size;
							}	
							else if($1.extra == 2 && $3.extra != 2){    // se primeiro e uma rx   
								$$.valorVar = $1.valorVar - $3.valorVar;
								$$.desloc = $1.desloc;
								$$.extra = 2;
							}
							else if($1.extra != 2 && $3.extra == 2){    // se segundo e uma rx   
								$$.valorVar = $1.valorVar - $3.valorVar;
								$$.desloc = $3.desloc;
								$$.extra = 2;
							}
							else if($1.extra == 2 && $3.extra == 2){   // se os dois for rx
								if($1.tipoVar >= $3.tipoVar){
									$$.valorVar = $1.valorVar - $3.valorVar;
									$$.desloc = $1.desloc;
									$$.extra = 2;
								}
								else{
									$$.valorVar = $1.valorVar - $3.valorVar;
									$$.desloc = $3.desloc;
									$$.extra = 2;
								}
							}
							gera_Cod(&$1, &$3, &$$, op);			
							
							base++;
						}



		| 	expr MULT expr		{	char *op;	
							int auxTipo = verificaTipo(&$1, &$3);
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							$$.tipoVar = auxTipo; $$.size = auxSize;
							
							if($1.tipoVar != INT || $3.tipoVar != INT){op = malloc(sizeof(char)*(strlen("FMULT") + 1));strcpy(op,"FMULT");}
							else{op = malloc(sizeof(char)*(strlen("MULT") + 1));strcpy(op,"MULT");}

							if($1.extra != 2 && $3.extra != 2){
								$$.valorVar = $1.valorVar * $3.valorVar;
								$$.desloc = deslocamentorx;
								$$.extra = 2;
								deslocamentorx += $$.size;
							}	
							else if($1.extra == 2 && $3.extra != 2){    // se primeiro e uma rx   
								$$.valorVar = $1.valorVar * $3.valorVar;
								$$.desloc = $1.desloc;
								$$.extra = 2;
							}
							else if($1.extra != 2 && $3.extra == 2){    // se segundo e uma rx   
								$$.valorVar = $1.valorVar * $3.valorVar;
								$$.desloc = $3.desloc;
								$$.extra = 2;
							}
							else if($1.extra == 2 && $3.extra == 2){   // se os dois for rx
								if($1.tipoVar >= $3.tipoVar){
									$$.valorVar = $1.valorVar * $3.valorVar;
									$$.desloc = $1.desloc;
									$$.extra = 2;
								}
								else{
									$$.valorVar = $1.valorVar * $3.valorVar;
									$$.desloc = $3.desloc;
									$$.extra = 2;
								}
							}
							
							gera_Cod(&$1, &$3, &$$, op);
							
							base++;
						}



		| 	expr DIV expr		{	char *op;	
							int auxTipo = verificaTipo(&$1, &$3, &$$);
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							$$.tipoVar = auxTipo; $$.size = auxSize;

							if($1.tipoVar != INT || $3.tipoVar != INT){op = malloc(sizeof(char)*(strlen("FDIV") + 1));strcpy(op,"FDIV");}
							else{op = malloc(sizeof(char)*(strlen("DIV") + 1));strcpy(op,"DIV");}



							if($1.extra != 2 && $3.extra != 2){
								$$.valorVar = $1.valorVar / $3.valorVar;
								$$.desloc = deslocamentorx;
								$$.extra = 2;
								deslocamentorx += $$.size;
							}	
							else if($1.extra == 2 && $3.extra != 2){    // se primeiro e uma rx   
								$$.valorVar = $1.valorVar / $3.valorVar;
								$$.desloc = $1.desloc;
								$$.extra = 2;
							}
							else if($1.extra != 2 && $3.extra == 2){    // se segundo e uma rx   
								$$.valorVar = $1.valorVar / $3.valorVar;
								$$.desloc = $3.desloc;
								$$.extra = 2;
							}
							else if($1.extra == 2 && $3.extra == 2){   // se os dois for rx
								if($1.tipoVar >= $3.tipoVar){
									$$.valorVar = $1.valorVar / $3.valorVar;
									$$.desloc = $1.desloc;
									$$.extra = 2;
								}
								else{
									$$.valorVar = $1.valorVar / $3.valorVar;
									$$.desloc = $3.desloc;
									$$.extra = 2;
								}
							}
							gera_Cod(&$1, &$3, &$$, op);

							
							base++;
						}

		| 	'('expr')'		{
							$$.valorVar = $2.valorVar;
							$$.desloc = $2.desloc;
							$$.tipoVar = $2.tipoVar;
							$$.size = $2.size;
							$$.extra = $2.extra;
							$$.codigo = $2.codigo; 
							//printf("Regra 13.parentese %0.1lf \n", $$.valorVar);

						}
		| 	INT_LIT			
						{
							$$.valorVar = $1.valorinNum;
							$$.tipoVar = INT;
							$$.size = $1.sizeLit;
							$$.codigo = NULL;
							$$.desloc = 0;
							$$.extra = 0;
							//printf("%3d: %3d(RX)  := %04d \n", base, $$.desloc, $1.valorinNum);
						}
		| 	F_LIT 			{
							$$.valorVar = $1.valorinNum;
							$$.tipoVar = FLOAT;
							$$.size = $1.sizeLit;
							$$.codigo = NULL;
							$$.desloc = 0;
							$$.extra = 0;
							//printf("%3d: %3d(RX)  :=%d \n", base, $$.desloc, $$.valorVar);
							base++;

						}
		| 	lvalue 			{
							$$.valorVar= $1.valorVar;
							$$.literal = $1.literal;
							$$.desloc =  $1.desloc;
							$$.size = $1.size;
							$$.extra = $1.extra;
							$$.codigo = NULL;
						}

		| 	chamada_Proced 		{printf("Regra 13.10  \n");}
		;



chamada_Proced	:	IDF'('expr proced_Expr	
		;

proced_Expr	:	')'			
		| 	','expr proced_Expr	
		;

enun_simples 	:	expr			
		| 	instr_Controle		
		;

instr_Controle	:	if_expr			
		| 	while_expr		
		;

if_expr		:	IF'('bool_expr')'THEN acoes fim_if 	
		;

fim_if		:	END					
		| 	ELSE acoes END				
		;

while_expr	:	WHILE'('bool_expr')''{'acoes'}'		
		| 						
		;

bool_expr	:	TRUE					
		| 	FALSE					
		| 	'('bool_expr')'				
		| 	bool_expr AND bool_expr			
		| 	bool_expr OR bool_expr			
		| 	negar bool_expr				
		| 	expr '>' expr				
		| 	expr '<' expr				
		| 	expr LE expr				
		| 	expr GE expr				
		| 	expr EQ expr				
		;

negar		:	NOT					
		;


%%



/**  identificadores menos simples. */

/*
int yywrap(){
   return(1);
}
*/




int yyerror(char *s){
  fprintf(stderr,"%s \n",s);	
}





int verificaTipo(struct var* arg1, struct var* arg2)
{
	if(arg1->tipoVar == CHAR || arg2->tipoVar == CHAR){ return -1;}
	if(arg1->tipoVar == INT && arg2->tipoVar == INT)
	{
		return INT; 
		
	}
	else if(arg1->tipoVar == FLOAT && arg2->tipoVar == FLOAT)
	{
		return FLOAT;						
	}
	else if(arg1->tipoVar == DOUBLE && arg2->tipoVar == DOUBLE)
	{
		return DOUBLE; 						
	}
	else{
		if(arg1->tipoVar == DOUBLE || arg2->tipoVar == DOUBLE){
			return -1; 						
		}
		else{
			return -1;  
		}
	}
}

void gera_Cod(struct var* arg1, struct var* arg2, struct var* result, char *op)  // 2 = RX  /   1 = SP  / 0 = INT OU FLOAT
{	fp = fopen("saida.txt","a");
	if(arg1->extra == 0 && arg2->extra == 0){
		if(result->tipoVar == FLOAT || result->tipoVar == DOUBLE){
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) FADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, result->desloc, op, arg2->valorVar);}
		else{	
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) ADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, result->desloc, op, arg2->valorVar);
		}
	}
	else if(arg1->extra == 0 && arg2->extra == 1){
		if(result->tipoVar == FLOAT || result->tipoVar == DOUBLE){
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) FADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(SP) \n", base, result->desloc, result->desloc, op, arg2->desloc);}
		else{	
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) ADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(SP) \n", base, result->desloc, result->desloc, op, arg2->desloc);
		}
	}
	else if(arg1->extra == 0 && arg2->extra == 2){
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, result->desloc, op, arg1->valorVar);
		//fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(RX) \n", base, result->desloc, result->desloc, op, arg2->desloc);
	}
	else if(arg1->extra == 1 && arg2->extra == 0){
		fprintf(fp, "%03d: %03d(RX)  := %03d(SP) %s %.1f \n", base, result->desloc, arg1->desloc, op, arg2->valorVar);
	}
	else if(arg1->extra == 1 && arg2->extra == 1){
		fprintf(fp, "%03d: %03d(RX)  := %03d(SP) %s %03d(SP) \n", base, result->desloc, arg1->desloc, op, arg2->desloc);
	}
	else if(arg1->extra == 2 && arg2->extra == 0){
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, arg1->desloc, op, arg2->valorVar);
	}
	else if(arg1->extra == 2 && arg2->extra == 1){
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(SP) \n", base, result->desloc, arg1->desloc, op, arg2->desloc);
	}
	
	else if(arg1->extra == 1 && arg2->extra == 2){
		fprintf(fp, "%03d: %03d(RX)  := %03d(SP) %s %03d(RX)\n", base, result->desloc, arg2->desloc, op, arg1->desloc);
	}
	else{
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(RX)\n", base, result->desloc, arg1->desloc, op, arg2->desloc);
	}
	fclose(fp);
}

int getTipo(int tipo)
{
	if(tipo == INT){ return 2;}
	else if(tipo == DOUBLE){ return 16;}
	else if(tipo == FLOAT){ return 4;}
	else { return 1;}
	
}
