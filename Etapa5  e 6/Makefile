# Makefile chamado pelo Makefile principal de ComFet/

# 'make' sem argumento vai resolver a depencia abaixo, e compilar comfet:
#   sem fazer a instalacao.
#
all: comfet
#
# 'comfet' depende de comfet.c (codigo fonte do parser) e lex.yy.c (codigo fonte
# do scanner).
comfet: comfet.c lex.yy.c
	gcc test3.c
	./a.out
#
# 'comfet.c' eh gerado pelo Yacc a partir de comfet.y.
# o comando yacc -d gera tanto y.tab.c como y.tab.h. 
# Apos ter criado y.tab.c, renomea-o para comfet.c - nota que nessa etapa, 
#    comfet.c passa a ser o parser e nao mais o scanner.
# Apos ter criado y.tab.h, renomea-o para tokens.h (que sera usado pelo 
#    scanner).
#
comfet.c: comfet.y
	yacc -d --verbose comfet.y;
	 mv y.tab.h tokens.h

# o scanner 'lex.yy.c' eh gerado pelo flex
# O flex usa como entrada 'scanner.l' encontrado em Etapa2/src, porem alterando
# o nome do procedimento "main" encontrado nele para que passe a se chamar
# 'main-etapa2'. Dessa forma, nao tera conflito com o main de comfet.c.
# OBSERVACAO: QUALQUER ALTERACAO EFETUADA NO SCANNER DEVE SER FEITA
# EM src/Etapa2/scanner.h !!
#
lex.yy.c: scanner.l
	flex scanner.l; mv lex.yy.c comfet.c

# o 'install' soh copia 'comfet' em Tests/, mas primeiro ele deve ter sido
# compilado, por isso a dependencia.
#

clean:
	rm comfet.c lex.yy.c tokens.h comfet
