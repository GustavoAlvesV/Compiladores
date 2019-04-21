//Definitions
%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>  
    #include "symbol_table.h"
    #include "stack.h"

    symbol_t stable;
    stack pilha = NULL;
    int deslocamento = 0;



    int yylex();
    int yyerror(char *s);
  
%}

//Tokens

%token INT
%token DOUBLE
%token FLOAT
%token CHAR

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

%left '+' '-'
%left '*' '/'
%left OR
%left AND
%left NOT


%union{
	char *name;
	struct{
		char *name;
		char tipo;
		double valor;
	}lit;
}


%type<lit>  F_LIT
%type<lit>  INT_LIT
%type<name> IDF
%type<name> lista_IDF

 
//Rules

%%
programa	:	declaracoes acoes 
		|	declaracoes
		|	acoes	
		;


// Declarações:

declaracoes	:	declaracao';' 
		|	declaracoes declaracao';'
		; 

declaracao 	:	lista_IDF':'tipos 
				{	
					while(!empty(pilha)){
				 	char* var;
					var = (char*) pop(&pilha);
					printf("Variavel: %s \n", var);
					}

				}
		; 


lista_IDF	:	lista_IDF','IDF 
				{push(&pilha,$3);printf("Regra 3.11  \n");} 	
		|	IDF		
				{push(&pilha,$1); printf("Regra 3.1  \n");} 
		;
		

tipos 		:	tipo   
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

acoes		: 	acoes';'comando {printf("Regra 7.1  \n");}
		| 	comando		{printf("Regra 7.2  \n");}
		;

comando		: 	atrib 		{printf("Regra 8.1  \n");}
		| 	enun_simples	{printf("Regra 8.2  \n");}
		;

atrib		: 	lvalue'='expr	{printf("Regra  9 \n");}
		;

// Gramática:
	
lvalue 		: 	IDF		{printf("Regra 10  \n");}
		| 	IDF'['lista_expr	{printf("Regra 10.1  \n");}
		;

lista_expr	:	expr','lista_expr	{printf("Regra 11.1  \n");}
		| 	expr']'			{printf("Regra 11.2  \n");}
		;

expr		:	termo maistermo		{printf("Regra 12  \n");}
		;

maistermo	:	'+' termo maistermo	{printf("Regra 13.1  \n");}
		| 	'-' termo maistermo	{printf("Regra 13.2  \n");}
		|	'*' termo maistermo	{printf("Regra 13.3  \n");}
		| 	'/' termo maistermo	{printf("Regra 13.4  \n");}
		| 				{printf("Regra 13.5  \n");}
		;

termo		:	'('expr')'		{printf("Regra 13.6  \n");}
		| 	INT_LIT			{printf("Regra 13.7  \n");}
		| 	F_LIT 			{printf("Regra 13.8  \n");}
		| 	lvalue 			{printf("Regra 13.9  \n");}
		| 	chamada_Proced 		{printf("Regra 13.10  \n");}
		;




chamada_Proced	:	IDF'('expr proced_Expr	{printf("Regra 14  \n");}
		;

proced_Expr	:	')'			{printf("Regra 15  \n");}
		| 	','expr proced_Expr	{printf("Regra 16  \n");}
		;

enun_simples 	:	expr			{printf("Regra 17  \n");}
		| 	instr_Controle		{printf("Regra 18  \n");}
		;

instr_Controle	:	if_expr			{printf("Regra 19  \n");}
		| 	while_expr		{printf("Regra 20  \n");}
		;

if_expr		:	IF'('bool_expr')'THEN acoes fim_if 	{printf("Regra 21  \n");}
		;

fim_if		:	END					{printf("Regra 22  \n");}
		| 	ELSE acoes END				{printf("Regra 23  \n");}
		;

while_expr	:	WHILE'('bool_expr')''{'acoes'}'		{printf("Regra 24  \n");}
		| 						{printf("Regra 25  \n");}
		;

bool_expr	:	TRUE					{printf("Regra 26  \n");}
		| 	FALSE					{printf("Regra 27  \n");}
		| 	'('bool_expr')'				{printf("Regra 28  \n");}
		| 	bool_expr AND bool_expr			{printf("Regra 29  \n");}
		| 	bool_expr OR bool_expr			{printf("Regra 30  \n");}
		| 	negar bool_expr				{printf("Regra 31  \n");}
		| 	expr '>' expr				{printf("Regra 32  \n");}
		| 	expr '<' expr				{printf("Regra 33  \n");}
		| 	expr LE expr				{printf("Regra 34  \n");}
		| 	expr GE expr				{printf("Regra 35  \n");}
		| 	expr EQ expr				{printf("Regra 36  \n");}
		;

negar		:	NOT					{printf("Regra 37  \n");}
		;

/* print 		:	INT_LIT					{printf("Regra 38  \n");}
		| 	F_LIT 					{printf("Regra 39  \n");}
		;*/

%%

/**  identificadores menos simples. */
/*
int main(int argc, char** argv) {
   return(yyparse());
}

int yywrap(){
   return(1);
}
*/
int yyerror(char *s){
  fprintf(stderr,"%s \n",s);	
}


