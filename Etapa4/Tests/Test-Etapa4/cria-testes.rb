#!/usr/bin/ruby -w
#
# Cria testes (programas C + inputs) a partir de arquivos de entrada do tipo:
#  %%% teste1 - identificadores simples
#  # isso eh comentario
#  nicolas  IDF
#  tmp0 IDF
#  %%% teste2 - outros identificadores
#  for FOR
#  ; ';'
#  # cada linha eh constituida de um string (sem espaco), qlqer espacamento
#  # branco, e depois o token a ser retornado.
#  Cada grupo de linhas depois de %%% testeX e ateh o %%% seguinte
#  sera usado para gerar um programa C 'testeX.c'
#  que devera efetuar um laco, reconhecer os strings contidos 
#  em "testeX-input.txt'
#  e retornar para cada um deles o token especificado.
#  o texto entre '-' e ateh o fim da linha sera usado no log do teste.
#

def dump(cfile, inname, comment)
   cfile.print <<-END
/** #{comment} */
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "comfet.c"

int main(int argc, char** argv) {
   int token;
   yyin = fopen("#{inname}", "r");
   END
end

def termina(cfile)
   cfile.print <<-END
   return(0);
}
   END
   cfile.close
end

ARGV.each do  |input_file|
   c_output = nil
   txt_output = nil
   File.open(input_file).each do |linha|
      if linha =~ /#/ then
        next
      end
      if linha =~ /\s*%%%\s*(\w+)\s+-(.*)$/ then
	 puts 'Writing everything to '+Regexp.last_match[1]+'.c'
	 if c_output != nil then
	    termina(c_output)
	    txt_output.close
         end
         c_output   = File.open(Regexp.last_match[1]+'.c','w')
         txt_output = File.open(Regexp.last_match[1]+'-input.txt','w')
	 comentario = Regexp.last_match[2]
	 dump(c_output, Regexp.last_match[1]+'-input.txt', comentario)
         next
      end
      if linha =~ /\s*(.*?)\s+(.*)\s*$/ then
         txt_output.puts(Regexp.last_match[1])
	 c_output.puts('   token=yylex();');
	 c_output.puts("   if (token != #{Regexp.last_match[2]})");
	 c_output.puts('      printf("ERROR.\n");'); 
      end
      # Qualquer outro caso eh um erro - ignoramos.
   end
   if c_output != nil then
       termina(c_output)
       txt_output.close
   end
   
end
