/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "comfet.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>  
#include "symbol_table.h"
#include "stack.h"
#define UNDEFINED_SYMBOL_ERROR -21	
#define TYPE_MISMATCH_ERROR -20

#define ERROR_UNDEFINED_SYMBOL(ref) printf("VARIAVEL %s NAO DECLARADA.\n", ref);return UNDEFINED_SYMBOL_ERROR;
#define ERROR_TYPE_MISMATCH() printf("ERROR DE TIPAGEM.\n");return TYPE_MISMATCH_ERROR;		


symbol_t stable;
stack pilha = NULL;
int deslocamento = 600;
int deslocamentorx = 0;
int base = 0;
FILE *fp, *fo;	
int yylex();
int yyerror(char *s);
int getTipo(int tipo);

#line 90 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 71 "comfet.y" /* yacc.c:355  */

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

#line 214 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    31,
      42,    36,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   117,   122,   123,   126,   150,   152,   157,
     158,   162,   163,   164,   165,   168,   169,   170,   178,   179,
     182,   183,   186,   215,   233,   236,   237,   243,   289,   334,
     380,   426,   436,   446,   457,   466,   471,   474,   475,   478,
     479,   482,   483,   486,   489,   490,   493,   494,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   510
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "FLOAT", "CHAR", "ADD",
  "SUB", "MULT", "DIV", "QUOTE", "DQUOTE", "LE", "GE", "EQ", "NE", "AND",
  "OR", "NOT", "IF", "THEN", "ELSE", "WHILE", "BRANCO", "IDF", "F_LIT",
  "INT_LIT", "TRUE", "FALSE", "END", "';'", "':'", "','", "'['", "']'",
  "'='", "'('", "')'", "'{'", "'}'", "'>'", "'<'", "$accept", "programa",
  "declaracoes", "declaracao", "lista_IDF", "tipos", "tipo", "lista_INT",
  "acoes", "comando", "atrib", "lvalue", "lista_expr", "expr",
  "chamada_Proced", "proced_Expr", "enun_simples", "instr_Controle",
  "if_expr", "fim_if", "while_expr", "bool_expr", "negar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    59,    58,    44,    91,    93,    61,    40,    41,   123,
     125,    62,    60
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -9

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,   -34,   -21,   102,   -35,   -35,     6,    35,    96,    18,
      32,    24,   -35,   -35,    40,   136,   -35,   -35,   -35,   -35,
     -35,    83,    83,     6,     6,    46,   -35,    80,   -35,    47,
      24,   -35,   144,    59,   105,     6,     6,     6,     6,     6,
     -35,   -35,   -35,    83,    53,    -8,    83,     3,   -35,    91,
      44,   -35,   -35,   -35,   -35,   -35,   -35,   -35,    57,   -35,
     -35,   136,    97,    97,   -35,   -35,     4,    10,     6,     6,
       6,     6,     6,    83,    83,    75,   120,    64,     6,   -35,
       6,   -35,   -35,    78,   -35,   136,   136,   136,   136,   136,
     -35,   100,   105,   105,   -35,    44,    81,   -31,    28,   -25,
     -35,   113,   114,   -35,   105,   -35,   -35,   -35,   -35,    95,
      84,   124,   -35,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      47,     0,     0,    23,    33,    32,     0,     0,    47,     0,
       0,     3,    19,    20,    34,    39,    35,    21,    40,    41,
      42,     0,     0,     0,     0,    23,    34,     0,     1,     0,
       2,     4,     0,     0,    47,     0,     0,     0,     0,     0,
      59,    48,    49,     0,     0,     0,     0,     0,    24,     0,
       0,    31,     5,    11,    12,    13,    14,     6,     9,     7,
      18,    22,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,    26,
       0,    37,    36,     0,    50,    56,    57,    58,    54,    55,
      51,    52,    47,    47,    25,     0,     0,    10,     0,     0,
      38,     0,     0,    16,    47,    44,    43,    46,    17,     0,
       0,     0,    45,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -35,   121,   -35,   -35,   -35,   -35,    -7,   118,
     -35,     0,    76,     1,   -35,    58,   -35,   -35,   -35,   -35,
     -35,   -17,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    57,    58,    97,    11,    12,
      13,    26,    48,    15,    16,    82,    17,    18,    19,   106,
      20,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      14,    30,   102,    21,   103,    47,    34,    27,    14,    73,
      74,    36,    37,    38,    39,   107,    22,    68,    69,    70,
      73,    74,    44,    44,    49,    50,    67,    73,    74,    76,
      75,    25,     4,     5,    14,    28,    61,    62,    63,    64,
      65,    77,    51,     6,    66,    71,    72,    44,    84,    31,
     104,    36,    37,    38,    39,    34,    90,    91,   105,    34,
      36,    37,    38,    39,    32,    33,    68,    69,    70,    85,
      86,    87,    88,    89,    44,    44,    35,    80,    52,    49,
      23,    95,    81,    24,    59,    98,    99,    36,    37,    38,
      39,    83,    14,    14,    71,    72,    92,   110,    36,    37,
      38,    39,    40,    93,    14,    96,    38,    39,    25,     4,
       5,    41,    42,   101,   112,    34,     1,    73,    51,     2,
      43,     3,     4,     5,    78,     1,    79,   111,     2,    29,
      25,     4,     5,     6,    -8,    -8,    23,    73,    74,    24,
     108,   109,     6,    36,    37,    38,    39,    53,    54,    55,
      56,   113,    60,   100,    94
};

static const yytype_uint8 yycheck[] =
{
       0,     8,    33,    37,    35,    22,    31,     6,     8,    17,
      18,     7,     8,     9,    10,    40,    37,    13,    14,    15,
      17,    18,    21,    22,    23,    24,    43,    17,    18,    46,
      38,    25,    26,    27,    34,     0,    35,    36,    37,    38,
      39,    38,    38,    37,    43,    41,    42,    46,    38,    31,
      22,     7,     8,     9,    10,    31,    73,    74,    30,    31,
       7,     8,     9,    10,    32,    33,    13,    14,    15,    68,
      69,    70,    71,    72,    73,    74,    36,    33,    31,    78,
      34,    80,    38,    37,    25,    92,    93,     7,     8,     9,
      10,    34,    92,    93,    41,    42,    21,   104,     7,     8,
       9,    10,    19,    39,   104,    27,     9,    10,    25,    26,
      27,    28,    29,    32,    30,    31,    20,    17,    38,    23,
      37,    25,    26,    27,    33,    20,    35,    32,    23,     8,
      25,    26,    27,    37,    32,    33,    34,    17,    18,    37,
      27,    27,    37,     7,     8,     9,    10,     3,     4,     5,
       6,    27,    34,    95,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    23,    25,    26,    27,    37,    44,    45,    46,
      47,    51,    52,    53,    54,    56,    57,    59,    60,    61,
      63,    37,    37,    34,    37,    25,    54,    56,     0,    46,
      51,    31,    32,    33,    31,    36,     7,     8,     9,    10,
      19,    28,    29,    37,    56,    64,    65,    64,    55,    56,
      56,    38,    31,     3,     4,     5,     6,    48,    49,    25,
      52,    56,    56,    56,    56,    56,    56,    64,    13,    14,
      15,    41,    42,    17,    18,    38,    64,    38,    33,    35,
      33,    38,    58,    34,    38,    56,    56,    56,    56,    56,
      64,    64,    21,    39,    55,    56,    27,    50,    51,    51,
      58,    32,    33,    35,    22,    30,    62,    40,    27,    27,
      51,    32,    30,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    47,    47,    48,
      48,    49,    49,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     3,     3,     1,     1,
       3,     1,     1,     1,     1,     5,     2,     3,     3,     1,
       1,     1,     3,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     4,     1,     3,     1,
       1,     1,     1,     7,     1,     3,     7,     0,     1,     1,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 127 "comfet.y" /* yacc.c:1646  */
    {	
				 	char* var;
					entry_t* idf;
					while(!empty(pilha)){
						var = (char*) pop(&pilha);
						idf = malloc(sizeof(entry_t));
						idf->name = malloc(sizeof(char)*(strlen(var) + 1));
						strcpy(idf->name, var);
						idf->valor = 0;
						idf->type = (yyvsp[0].type).tipoinNum;
						idf->size = (yyvsp[0].type).sizeTipo;
						idf->desloc = deslocamento;
						deslocamento += idf->size;
						printf("%03d: %03d:%03d(SP) %s := tipo: %d \n", base, idf->desloc, deslocamento, var, idf->type);
						//base = base + 1;
						insert(&stable,idf);
						//print_table(stable);
					}

				}
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 151 "comfet.y" /* yacc.c:1646  */
    {push(&pilha,(yyvsp[0].name));}
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 153 "comfet.y" /* yacc.c:1646  */
    {push(&pilha,(yyvsp[0].name));}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 157 "comfet.y" /* yacc.c:1646  */
    {(yyval.type).tipoinNum = (yyvsp[0].type).tipoinNum; (yyval.type).sizeTipo = (yyvsp[0].type).sizeTipo; }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 187 "comfet.y" /* yacc.c:1646  */
    {	
						fo = fopen("saida.txt","a");
						char* op;
						int auxTipo = verificaTipo(&(yyvsp[-2].var), &(yyvsp[0].var));
						if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
						if((yyvsp[-2].var).tipoVar != INT || (yyvsp[0].var).tipoVar != INT){op = malloc(sizeof(char)*(strlen("FMOVE") + 1));strcpy(op,"FMOVE");}
							else{op = malloc(sizeof(char)*(strlen("MOVE") + 1));strcpy(op,"MOVE");}

						if((yyvsp[0].var).extra == 0){  // = num
							fprintf(fo,"%03d: %03d(SP)  := %03d(SP) %s %.01f \n", base, (yyvsp[-2].var).desloc, (yyvsp[-2].var).desloc, op,  (yyvsp[0].var).valorVar);
						}
						else if((yyvsp[0].var).extra == 1){   // = idf
							fprintf(fo,"%03d: %03d(SP)  := %03d(SP) %s %03d(SP) \n", base, (yyvsp[-2].var).desloc, (yyvsp[-2].var).desloc, op, (yyvsp[0].var).desloc);
						}
						else{  // = rx
							fprintf(fo,"%03d: %03d(SP)  := %03d(SP) %s %03d(RX) \n", base, (yyvsp[-2].var).desloc, (yyvsp[-2].var).desloc, op, (yyvsp[0].var).desloc);
						}
						base++;
						if((yyvsp[-2].var).tipoVar != INT || (yyvsp[0].var).tipoVar != INT){op = malloc(sizeof(char)*(strlen("FPRINTF") + 1));strcpy(op,"FPRINTF");}
							else{op = malloc(sizeof(char)*(strlen("PRINTF") + 1));strcpy(op,"PRINTF");}
						fprintf(fo,"%03d: %s = %03d(SP) \n", base, op, (yyvsp[-2].var).desloc);
						base++;
						fclose(fo);
					}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 216 "comfet.y" /* yacc.c:1646  */
    {
							entry_t* var = NULL;
							var = lookup(stable, (yyvsp[0].name));
							if(var == NULL){
								ERROR_UNDEFINED_SYMBOL((yyvsp[0].name));
							}
							else{
								(yyval.var).valorVar = var->valor;
							    	(yyval.var).literal = var->name;
								(yyval.var).desloc = var->desloc;
								(yyval.var).tipoVar = var->type;
								(yyval.var).size = var->size;
								(yyval.var).extra = 1;
								(yyval.var).codigo = NULL;
							}
						}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 233 "comfet.y" /* yacc.c:1646  */
    {	}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 236 "comfet.y" /* yacc.c:1646  */
    {	}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 237 "comfet.y" /* yacc.c:1646  */
    {	}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 243 "comfet.y" /* yacc.c:1646  */
    {	char *op;	
							int auxTipo = verificaTipo(&(yyvsp[-2].var), &(yyvsp[0].var));
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							(yyval.var).tipoVar = auxTipo; (yyval.var).size = auxSize;
				
							if((yyvsp[-2].var).tipoVar != INT || (yyvsp[0].var).tipoVar != INT){op = malloc(sizeof(char)*(strlen("FADD") + 1));strcpy(op,"FADD");}
							else{op = malloc(sizeof(char)*(strlen("ADD") + 1));strcpy(op,"ADD");}


							if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra != 2){ // soma 2 idfs ou ints ou floats ou doubles // cria temporario pegando ultima endereço de memoria 
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar + (yyvsp[0].var).valorVar;
								(yyval.var).desloc = deslocamentorx;
								(yyval.var).extra = 2;  // a soma vira rx
								deslocamentorx += (yyval.var).size;   
							}	
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra != 2){    // se primeiro e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar + (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[-2].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra == 2){    // se segundo e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar + (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[0].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra == 2){   // se os dois for rx
								if((yyvsp[-2].var).tipoVar >= (yyvsp[0].var).tipoVar){
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar + (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[-2].var).desloc;
									(yyval.var).extra = 2;
								}
								else{
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar + (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[0].var).desloc;
									(yyval.var).extra = 2;
								}
							}

							
							gera_Cod(&(yyvsp[-2].var), &(yyvsp[0].var), &(yyval.var), op);
							base++;
						}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 289 "comfet.y" /* yacc.c:1646  */
    {	char *op;	
							int auxTipo = verificaTipo(&(yyvsp[-2].var), &(yyvsp[0].var));
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							(yyval.var).tipoVar = auxTipo; (yyval.var).size = auxSize;
							
							if((yyvsp[-2].var).tipoVar != INT || (yyvsp[0].var).tipoVar != INT){op = malloc(sizeof(char)*(strlen("FSUB") + 1));strcpy(op,"FSUB");}
							else{op = malloc(sizeof(char)*(strlen("SUB") + 1));strcpy(op,"SUB");}

							if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra != 2){
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar - (yyvsp[0].var).valorVar;
								(yyval.var).desloc = deslocamentorx;
								(yyval.var).extra = 2;
								deslocamentorx += (yyval.var).size;
							}	
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra != 2){    // se primeiro e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar - (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[-2].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra == 2){    // se segundo e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar - (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[0].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra == 2){   // se os dois for rx
								if((yyvsp[-2].var).tipoVar >= (yyvsp[0].var).tipoVar){
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar - (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[-2].var).desloc;
									(yyval.var).extra = 2;
								}
								else{
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar - (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[0].var).desloc;
									(yyval.var).extra = 2;
								}
							}
							gera_Cod(&(yyvsp[-2].var), &(yyvsp[0].var), &(yyval.var), op);			
							
							base++;
						}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 334 "comfet.y" /* yacc.c:1646  */
    {	char *op;	
							int auxTipo = verificaTipo(&(yyvsp[-2].var), &(yyvsp[0].var));
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							(yyval.var).tipoVar = auxTipo; (yyval.var).size = auxSize;
							
							if((yyvsp[-2].var).tipoVar != INT || (yyvsp[0].var).tipoVar != INT){op = malloc(sizeof(char)*(strlen("FMULT") + 1));strcpy(op,"FMULT");}
							else{op = malloc(sizeof(char)*(strlen("MULT") + 1));strcpy(op,"MULT");}

							if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra != 2){
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar * (yyvsp[0].var).valorVar;
								(yyval.var).desloc = deslocamentorx;
								(yyval.var).extra = 2;
								deslocamentorx += (yyval.var).size;
							}	
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra != 2){    // se primeiro e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar * (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[-2].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra == 2){    // se segundo e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar * (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[0].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra == 2){   // se os dois for rx
								if((yyvsp[-2].var).tipoVar >= (yyvsp[0].var).tipoVar){
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar * (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[-2].var).desloc;
									(yyval.var).extra = 2;
								}
								else{
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar * (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[0].var).desloc;
									(yyval.var).extra = 2;
								}
							}
							
							gera_Cod(&(yyvsp[-2].var), &(yyvsp[0].var), &(yyval.var), op);
							
							base++;
						}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 380 "comfet.y" /* yacc.c:1646  */
    {	char *op;	
							int auxTipo = verificaTipo(&(yyvsp[-2].var), &(yyvsp[0].var), &(yyval.var));
							if(auxTipo < 0){ERROR_TYPE_MISMATCH();}
							int auxSize = getTipo(auxTipo);

							(yyval.var).tipoVar = auxTipo; (yyval.var).size = auxSize;

							if((yyvsp[-2].var).tipoVar != INT || (yyvsp[0].var).tipoVar != INT){op = malloc(sizeof(char)*(strlen("FDIV") + 1));strcpy(op,"FDIV");}
							else{op = malloc(sizeof(char)*(strlen("DIV") + 1));strcpy(op,"DIV");}



							if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra != 2){
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar / (yyvsp[0].var).valorVar;
								(yyval.var).desloc = deslocamentorx;
								(yyval.var).extra = 2;
								deslocamentorx += (yyval.var).size;
							}	
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra != 2){    // se primeiro e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar / (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[-2].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra != 2 && (yyvsp[0].var).extra == 2){    // se segundo e uma rx   
								(yyval.var).valorVar = (yyvsp[-2].var).valorVar / (yyvsp[0].var).valorVar;
								(yyval.var).desloc = (yyvsp[0].var).desloc;
								(yyval.var).extra = 2;
							}
							else if((yyvsp[-2].var).extra == 2 && (yyvsp[0].var).extra == 2){   // se os dois for rx
								if((yyvsp[-2].var).tipoVar >= (yyvsp[0].var).tipoVar){
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar / (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[-2].var).desloc;
									(yyval.var).extra = 2;
								}
								else{
									(yyval.var).valorVar = (yyvsp[-2].var).valorVar / (yyvsp[0].var).valorVar;
									(yyval.var).desloc = (yyvsp[0].var).desloc;
									(yyval.var).extra = 2;
								}
							}
							gera_Cod(&(yyvsp[-2].var), &(yyvsp[0].var), &(yyval.var), op);

							
							base++;
						}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 426 "comfet.y" /* yacc.c:1646  */
    {
							(yyval.var).valorVar = (yyvsp[-1].var).valorVar;
							(yyval.var).desloc = (yyvsp[-1].var).desloc;
							(yyval.var).tipoVar = (yyvsp[-1].var).tipoVar;
							(yyval.var).size = (yyvsp[-1].var).size;
							(yyval.var).extra = (yyvsp[-1].var).extra;
							(yyval.var).codigo = (yyvsp[-1].var).codigo; 
							//printf("Regra 13.parentese %0.1lf \n", $$.valorVar);

						}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 437 "comfet.y" /* yacc.c:1646  */
    {
							(yyval.var).valorVar = (yyvsp[0].lit).valorinNum;
							(yyval.var).tipoVar = INT;
							(yyval.var).size = (yyvsp[0].lit).sizeLit;
							(yyval.var).codigo = NULL;
							(yyval.var).desloc = 0;
							(yyval.var).extra = 0;
							//printf("%3d: %3d(RX)  := %04d \n", base, $$.desloc, $1.valorinNum);
						}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 446 "comfet.y" /* yacc.c:1646  */
    {
							(yyval.var).valorVar = (yyvsp[0].lit).valorinNum;
							(yyval.var).tipoVar = FLOAT;
							(yyval.var).size = (yyvsp[0].lit).sizeLit;
							(yyval.var).codigo = NULL;
							(yyval.var).desloc = 0;
							(yyval.var).extra = 0;
							//printf("%3d: %3d(RX)  :=%d \n", base, $$.desloc, $$.valorVar);
							base++;

						}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 457 "comfet.y" /* yacc.c:1646  */
    {
							(yyval.var).valorVar= (yyvsp[0].var).valorVar;
							(yyval.var).literal = (yyvsp[0].var).literal;
							(yyval.var).desloc =  (yyvsp[0].var).desloc;
							(yyval.var).size = (yyvsp[0].var).size;
							(yyval.var).extra = (yyvsp[0].var).extra;
							(yyval.var).codigo = NULL;
						}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 466 "comfet.y" /* yacc.c:1646  */
    {printf("Regra 13.10  \n");}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1759 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 514 "comfet.y" /* yacc.c:1906  */




/**  identificadores menos simples. */

/*
int yywrap(){
   return(1);
}
*/




int yyerror(char *s){
  fprintf(stderr,"%s \n",s);	
}





int verificaTipo(struct var* arg1, struct var* arg2)
{
	if(arg1->tipoVar == CHAR || arg2->tipoVar == CHAR){ return -1;}
	if(arg1->tipoVar == INT && arg2->tipoVar == INT)
	{
		return INT; 
		
	}
	else if(arg1->tipoVar == FLOAT && arg2->tipoVar == FLOAT)
	{
		return FLOAT;						
	}
	else if(arg1->tipoVar == DOUBLE && arg2->tipoVar == DOUBLE)
	{
		return DOUBLE; 						
	}
	else{
		if(arg1->tipoVar == DOUBLE || arg2->tipoVar == DOUBLE){
			return -1; 						
		}
		else{
			return -1;  
		}
	}
}

void gera_Cod(struct var* arg1, struct var* arg2, struct var* result, char *op)  // 2 = RX  /   1 = SP  / 0 = INT OU FLOAT
{	fp = fopen("saida.txt","a");
	if(arg1->extra == 0 && arg2->extra == 0){
		if(result->tipoVar == FLOAT || result->tipoVar == DOUBLE){
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) FADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, result->desloc, op, arg2->valorVar);}
		else{	
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) ADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, result->desloc, op, arg2->valorVar);
		}
	}
	else if(arg1->extra == 0 && arg2->extra == 1){
		if(result->tipoVar == FLOAT || result->tipoVar == DOUBLE){
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) FADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(SP) \n", base, result->desloc, result->desloc, op, arg2->desloc);}
		else{	
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) ADD %.1f \n", base, result->desloc, result->desloc, arg1->valorVar);
			fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(SP) \n", base, result->desloc, result->desloc, op, arg2->desloc);
		}
	}
	else if(arg1->extra == 0 && arg2->extra == 2){
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, result->desloc, op, arg1->valorVar);
		//fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(RX) \n", base, result->desloc, result->desloc, op, arg2->desloc);
	}
	else if(arg1->extra == 1 && arg2->extra == 0){
		fprintf(fp, "%03d: %03d(RX)  := %03d(SP) %s %.1f \n", base, result->desloc, arg1->desloc, op, arg2->valorVar);
	}
	else if(arg1->extra == 1 && arg2->extra == 1){
		fprintf(fp, "%03d: %03d(RX)  := %03d(SP) %s %03d(SP) \n", base, result->desloc, arg1->desloc, op, arg2->desloc);
	}
	else if(arg1->extra == 2 && arg2->extra == 0){
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %.1f \n", base, result->desloc, arg1->desloc, op, arg2->valorVar);
	}
	else if(arg1->extra == 2 && arg2->extra == 1){
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(SP) \n", base, result->desloc, arg1->desloc, op, arg2->desloc);
	}
	
	else if(arg1->extra == 1 && arg2->extra == 2){
		fprintf(fp, "%03d: %03d(RX)  := %03d(SP) %s %03d(RX)\n", base, result->desloc, arg2->desloc, op, arg1->desloc);
	}
	else{
		fprintf(fp, "%03d: %03d(RX)  := %03d(RX) %s %03d(RX)\n", base, result->desloc, arg1->desloc, op, arg2->desloc);
	}
	fclose(fp);
}

int getTipo(int tipo)
{
	if(tipo == INT){ return 2;}
	else if(tipo == DOUBLE){ return 16;}
	else if(tipo == FLOAT){ return 4;}
	else { return 1;}
	
}
