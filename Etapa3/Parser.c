/**  retorna um caractere */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "symbol_table.h"
symbol_t stable;
#include "comfet.c"
#include "stack.c"



int main(int argc, char* argv[]) {
	int token;
//Não Terminais
	int const E = 11;
	int const X = 12;
//Terminais
	int sADD = ADD;
	int sSUB = SUB;
	int sMULT = MULT;
	int sDIV = DIV;
	int sA_PAR = A_PAR;
	int sF_PAR = F_PAR;
	int sIDF = IDF;
	int sINT_LIT = INT_LIT;
	int sF_LIT = F_LIT;
	int sVAZIO = VAZIO;
	

//Tabela de símbolo
   init_table( &stable );
	
//Tabela Sintática M
	//Ordem SIMBOLO    '('     		')'      	'+'      	'-'      	'*'      	'/'       		F_LIT      	INT_LIT      	 IDF      	$
	//E
	//X

	int M[2][10] = {{1,0,0,0,0,0,4,3,2,0},{0,9,5,6,7,8,0,0,0,9}}; //Valores representam as regras da grámatica (Arquivo grámatica contém as regras)
	int produzido;  //Resultado da consulta da tabela M[x][a], onde x = Nao_Terminal / a = Terminal

//Declara e inicia PIlha com E (valor de start)

	stack pilha;
	push(&pilha,(void*) &E);
	int* symbol_stack = NULL;  //variável que recebe valor da pilha a partir do pop pop;

//BUffer (Carrega arquivo txt)
	yyin = fopen("test.txt", "r"); //passar arquivo por cmd
	if(!yyin) {
	      printf("Error: could not find file !\n");
	      exit(-1);
  	 }

// Busca token para iniciar análise

	token = yylex();

//Comeca Análise Sintática

/*Lembrar 3 Possibilidade
	A = Valor do Buffer
	X = Valor desempilhado

	Sendo X Terminais:
	 1) X = A = $(vazio), FIM  
	 2) X = A != $, remove X, avança a (chama yylex())

	Sendo X Não-Terminais:
	 3) Consulta tabele M[X,A], subst. X pelo valor produzido.
*/ 
	if(token > 0){ //se token == 0 significa o fim do fluxo de entrada ou não existe mais token para ser chamado.

		while(empty(pilha) == 0){ //enquanto pilha nao estiver cheia, aqui busca-se zerar a pilha e o fluxo de entrada juntos.

			symbol_stack = (int*) pop(&pilha);
			printf("Valor desempilhado: %i.\n ", *symbol_stack);
			printf("Valor BUffer: %i.\n ", token);
			if(*symbol_stack == E || *symbol_stack == X){	//Verifica é Não_Terminal: Case 3.
				
				produzido = M[(*symbol_stack)- 11][token - 1]; // -11 PORQUE os valores da matriz começa de 0 e as das variáveis terinais começa de 11. // -1 E PORQUE os valores da matriz começa de 0 e as das variáveis terinais começa de 1.

				printf("M[%i][%i].\n ", (*symbol_stack)- 11, token - 1);
				printf("Produzido: %i.\n ", produzido);

				//verificar os casos que são as regras da gramática
				if(produzido == 1){// 1) E -> '(' E ')' X
					push(&pilha,(void*) &X);
					push(&pilha,(void*) &sF_PAR);	
					push(&pilha,(void*) &E);
					push(&pilha,(void*) &sA_PAR);
				}
				else if(produzido == 2){
					// 2) E -> IDF X
					push(&pilha,(void*) &X);
					push(&pilha,(void*) &sIDF);
				}
				else if(produzido == 3){// 3) E -> INT_LIT X
					push(&pilha,(void*) &X);
					push(&pilha,(void*) &sINT_LIT);	
				}
				else if(produzido == 4){// 4) E -> F_LIT X
					push(&pilha,(void*) &X);
					push(&pilha,(void*) &sF_LIT);
				
				}
				else if(produzido == 5){// 5) X -> '+' E
					push(&pilha,(void*) &E);
					push(&pilha,(void*) &sADD);
				}
				else if(produzido == 6){// 6) X -> '-' E
					push(&pilha,(void*) &E);
					push(&pilha,(void*) &sSUB);
				}
				else if(produzido == 7){// 7) X -> '*' E
					push(&pilha,(void*) &E);
					push(&pilha,(void*) &sMULT);
				}
				else if(produzido == 8){// 8) X -> '/' E
					push(&pilha,(void*) &E);
					push(&pilha,(void*) &sDIV);
				}
				else if(produzido == 9){// 9) X -> &
					push(&pilha,(void*) &sVAZIO);
				}
				else {
				printf("ERROR, PRUDUÇÃO ERRADA.\n");
						exit(0);
				}
			}// Verificar é um Terminal: Caso 1 e 2;
			else{
				if(*symbol_stack == token ){ //CASO 1 e 2
					printf("SAIU DO BUFFER %i e da Pilha %i.\n", token, *symbol_stack);
					token = yylex();
					if(token == 0){token = sVAZIO;
					if(*symbol_stack==10){printf("Okay.\n");break;}
					}

				}
				else if(*symbol_stack != token && *symbol_stack == sVAZIO){ //VAZIO 
				}
				else{ // ERRO
					printf("ERROR, VALOR NAO DEFINIDO");
					exit(0);
				} 
				
			}
		}

	}
	fclose(yyin);
	return(0);
}

