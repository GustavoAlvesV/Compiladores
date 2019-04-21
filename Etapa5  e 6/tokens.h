/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    DOUBLE = 259,
    FLOAT = 260,
    CHAR = 261,
    ADD = 262,
    SUB = 263,
    MULT = 264,
    DIV = 265,
    QUOTE = 266,
    DQUOTE = 267,
    LE = 268,
    GE = 269,
    EQ = 270,
    NE = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    WHILE = 278,
    BRANCO = 279,
    IDF = 280,
    F_LIT = 281,
    INT_LIT = 282,
    TRUE = 283,
    FALSE = 284,
    END = 285
  };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define FLOAT 260
#define CHAR 261
#define ADD 262
#define SUB 263
#define MULT 264
#define DIV 265
#define QUOTE 266
#define DQUOTE 267
#define LE 268
#define GE 269
#define EQ 270
#define NE 271
#define AND 272
#define OR 273
#define NOT 274
#define IF 275
#define THEN 276
#define ELSE 277
#define WHILE 278
#define BRANCO 279
#define IDF 280
#define F_LIT 281
#define INT_LIT 282
#define TRUE 283
#define FALSE 284
#define END 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 71 "comfet.y" /* yacc.c:1909  */

	char *name; // PARA IDF
	struct type{
		int tipoinNum;
		int sizeTipo;
	}type;

	struct lit{
		char *valorinText;
		int sizeLit;
		double valorinNum;
	}lit;  // para INT E FLOAT

	struct var{
		char* literal;  // nome da variavel se for variavel
		double valorVar;   //valor da variavel, inicial = 0
	        int tipoVar;   	// tipo da variavel 
	        int size;    	//tamanho para aquele tipo
	        int desloc;   // posiçao da memoria que ela inicia
		void* codigo;
		int extra;   // se é idf ou unumm ou um RX
	}var;  // PARA ADM VARIAVEL 

#line 138 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
