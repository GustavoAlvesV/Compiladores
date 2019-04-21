/**  identificadores menos simples. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.c"

int yyparse();


int main(int argc, char** argv) {
   //init_table( &stable );
   yyin = fopen("test3-input.txt", "r");
   if (!yyparse()) {
      printf("OK.\n");
   }
   else {
	printf("ERROR.\n");
   }
   return(0);
}

