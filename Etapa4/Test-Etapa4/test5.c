/**  numeros com virgula, casos simples */
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "comfet.c"

int main(int argc, char** argv) {
   int token;
   yyin = fopen("test5-input.txt", "r");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   token=yylex();
   if (token != F_LIT)
      printf("ERROR.\n");
   return(0);
}
