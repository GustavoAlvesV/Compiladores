 /* Secao das declaracoes */

%option noyywrap
  /* Sera copiado no .c final */
%{
    #include <stdlib.h>
    #include <string.h>
   #include "symbol_table.c"
    /* este include eh importante... */
    #include "tokens.h"
  
%}
 
  /* Definicoes regulares */
digito      	[0-9]
letra		[A-Za-z]
branco 		[ |\t|\n]
id		[A-Za-z0-9_]

%%
 /* Secao das Regras de traducao */
 /* O que consta aqui eh puramente ilustrativo... 
  * Ver tambem "tokens.h" para a definicao de DIG e OPCMP
  */
  
(inteiro|integer)			{ return( INT ); }
"double"		 		{ return( DOUBLE ); }
"float"			 		{ return( FLOAT ); }
"char"			 		{ return( CHAR ); }

"*"						{ return( '*' ) ; }
"+"						{ return( '+' ) ; }
"-"						{ return( '-' ) ; }
"/"						{ return( '/') ; }

","						{ return( ',' ) ; }
";"						{ return( ';' ) ; }

"'"						{ return( QUOTE ) ; }
"\""					{ return( DQUOTE ) ; }

"("						{ return( '(' ) ; }
")"						{ return( ')' ) ; }
"["						{ return( '[' ) ; }
"]"						{ return( ']' ) ; }
"{"						{ return( '{' ) ; }
"}"						{ return( '}' ) ; }

"<"						{ return( '<' ) ; }
">"						{ return( '>' ) ; }
"="						{ return( '=' ) ; }

"<="					{ return( LE ) ; }
">="					{ return( GE ) ; }
"=="					{ return( EQ ) ; }
"!="					{ return( NE ) ; }

"&&"					{ return( AND ) ; }
"||"					{ return( OR ) ; }
"!"						{ return( NOT ) ; }
"if"					{ return( IF ) ; }
"then"					{ return( THEN ) ; }
"else"					{ return( ELSE ) ; }
"while"					{ return( WHILE ) ; }

{branco}+				{}


{letra}{id}*				{
							entry_t *idf;
							idf = (entry_t*)malloc(sizeof(entry_t));;
							idf->name = (char*)malloc(sizeof(char)*(strlen(yytext) + 1));
							idf->name = yytext;
							insert(&stable, idf);
							return(IDF); }
							
{digito}+				{return(INT_LIT); }

({digito}*\.{digito}+([Ee][+-]{digito}+)?)	{ return(F_LIT); }

.                     	{ printf("Erro lexical - caractere nao reconhecido: %c.\n", yytext[0]);  exit(-1); }

%%


