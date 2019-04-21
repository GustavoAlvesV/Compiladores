/**  casos triviais */
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "comfet.c"

int main(int argc, char** argv) {
   int token;
   yyin = fopen("test0-input.txt", "r");
   token=yylex();
   if (token != INT)
      printf("ERROR.\n");
   token=yylex();
   if (token != DOUBLE)
      printf("ERROR.\n");
   token=yylex();
   if (token != FLOAT)
      printf("ERROR.\n");
   token=yylex();
   if (token != CHAR)
      printf("ERROR.\n");
   token=yylex();
   if (token != QUOTE)
      printf("ERROR.\n");
   token=yylex();
   if (token != DQUOTE)
      printf("ERROR.\n");
   token=yylex();
   if (token != LE)
      printf("ERROR.\n");
   token=yylex();
   if (token != GE)
      printf("ERROR.\n");
   token=yylex();
   if (token != EQ)
      printf("ERROR.\n");
   token=yylex();
   if (token != NE)
      printf("ERROR.\n");
   token=yylex();
   if (token != AND)
      printf("ERROR.\n");
   token=yylex();
   if (token != OR)
      printf("ERROR.\n");
   token=yylex();
   if (token != NOT)
      printf("ERROR.\n");
   token=yylex();
   if (token != IF)
      printf("ERROR.\n");
   token=yylex();
   if (token != THEN)
      printf("ERROR.\n");
   token=yylex();
   if (token != ELSE)
      printf("ERROR.\n");
   token=yylex();
   if (token != WHILE)
      printf("ERROR.\n");
   return(0);
}
