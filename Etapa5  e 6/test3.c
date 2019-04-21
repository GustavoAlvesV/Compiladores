/**  identificadores menos simples. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comfet.c"    
#include "symbol_table.c"
#include "stack.c"





int main(int argc, char** argv) {
   FILE *op = fopen("saida.txt","w");
   fclose(op);
   init_table( &stable );
   init_stack( &pilha);
   yyin = fopen("test3-input.txt", "r");
   if (!yyparse()) {
      printf("OK.\n");
   }
   else {
	printf("ERROR.\n");
   }
   return(0);
}

