/**  identificadores simples */
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "comfet.c"

int main(int argc, char** argv) {
   int token;
   yyin = fopen("test2-input.txt", "r");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   token=yylex();
   if (token != IDF)
      printf("ERROR.\n");
   return(0);
}
