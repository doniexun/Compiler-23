
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "y.y"

#include "symTable.h"
#include "lex.yy.c"
#define Max 100
//#include "operator.h"

//expression's struct
typedef struct expType expType;
struct expType {
	char *name;
	Types type;
	int ival;
	float dval;
	char *sval;
	int bval;
};

//struct for subprogram checking
typedef struct func func;
struct func {
	symTable *mSym;
	symTable *var[100];
	int varNum;
	scope *link;
};

extern int yylex(void);

Types arithmeticCheck(expType *e1, expType *e2);
int isIntOrReal(Types t);
expType* expGenerate(Types t);
int expTypeCheck(expType *e1, expType *e2);
func* createFunc();
void idCondition(char *id);


Types tTemp;
int dimesParam;
Attrs aTemp;

scope *tempScope;
symTable *tempSym;
Types tempType;

int tempInt;
float tempReal;
char *tempStr;
int tempBool;

func *tempFunc = NULL;
func *funcAry[100];
int funcNum = 0;
int varNum = 0;
char *funcName;

symTable *table[100];
int vCurrent = 0;

//Identifier flag(for different condition)
int funcPara = 0;
int funcVaType = 0;
int funcCons = 0;
int funcDecl = 0;
int funcCall = 0;
int subrCall = 0;
int globalVa = 0;
int inFunc = 0;

FILE *file;
char *className;

int isLoop = 0;
int isLoopAss = 0;
int inc;
symTable *incV;
int labelNum = 0;
int loopifNum = 0;
int tempIndex;
int labelStack[100];


/* Line 189 of yacc.c  */
#line 155 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGERC = 258,
     REALC = 259,
     CHARC = 260,
     LOGICALC = 261,
     ID = 262,
     STRINGC = 263,
     LPARENTHESIS = 264,
     RPARENTHESIS = 265,
     COMMA = 266,
     COLON = 267,
     CCOLON = 268,
     SEMICOLON = 269,
     LBRACKET = 270,
     RBRACKET = 271,
     LBRACE = 272,
     RBRACE = 273,
     INTEGER = 274,
     REAL = 275,
     LOGICAL = 276,
     CHARACTER = 277,
     CALL = 278,
     CASE = 279,
     CLOSE = 280,
     CONTINUE = 281,
     CYCLE = 282,
     DATA = 283,
     DIMENSION = 284,
     DO = 285,
     END = 286,
     EXIT = 287,
     FUNCTION = 288,
     GOTO = 289,
     PROCEDURE = 290,
     PARAMETER = 291,
     PRINT = 292,
     PRINTLN = 293,
     POINTER = 294,
     PROGRAM = 295,
     RECURSIVE = 296,
     RETURN = 297,
     SELECT = 298,
     STOP = 299,
     SUBROUTINE = 300,
     TYPE = 301,
     PERCENT = 302,
     CONCAT = 303,
     PASSIGNMENT = 304,
     INTERFACE = 305,
     THEN = 306,
     IF = 307,
     READ = 308,
     COMMON = 309,
     IFX = 310,
     ELSE = 311,
     NEQV = 312,
     EQV = 313,
     OR = 314,
     AND = 315,
     NOT = 316,
     NE = 317,
     EQ = 318,
     GT = 319,
     GE = 320,
     LE = 321,
     LT = 322,
     EXP = 323,
     UMINUS = 324
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 82 "y.y"

	int ival;
	float dval;
	char cval;
	int bval;
	struct expType *epty;
	char *sval;
	symTable *sym; // ID or INTEGERC or REALC



/* Line 214 of yacc.c  */
#line 272 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 284 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  236

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      75,    76,    71,    69,    77,    70,     2,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,    79,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    19,    20,    21,    22,
      23,    39,    40,    41,    42,    43,    59,    60,    63,    66,
      69,    72,    73,    76,    80,    87,    88,    94,   100,   107,
     109,   111,   113,   115,   120,   121,   122,   123,   124,   138,
     139,   140,   141,   155,   156,   159,   162,   165,   168,   171,
     174,   175,   176,   185,   186,   191,   192,   193,   197,   198,
     202,   206,   207,   215,   216,   217,   218,   230,   231,   240,
     244,   246,   247,   251,   252,   254,   256,   258,   260,   262,
     263,   267,   269,   274,   279,   281,   283,   286,   287,   291,
     295,   299,   303,   306,   310,   314,   318,   322,   326,   330,
     331,   335,   337,   339,   341,   343,   347,   348,   352,   354,
     355,   357,   359,   361,   364,   367
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      81,     0,    -1,    -1,    -1,    -1,    40,     7,    82,    94,
     101,    83,   109,    31,    40,     7,    84,    85,    -1,    -1,
      -1,    -1,    -1,    45,     7,    86,    75,   128,    76,    87,
      94,    88,   109,    31,    45,     7,    89,    85,    -1,    -1,
      -1,    -1,    -1,    33,     7,    90,    75,   128,    76,    91,
      94,    92,   109,    31,    33,     7,    93,    85,    -1,    -1,
      95,    94,    -1,    96,    94,    -1,    98,    94,    -1,    99,
      94,    -1,    -1,   127,   129,    -1,   127,    13,   129,    -1,
     127,    77,   130,   131,    13,   129,    -1,    -1,    54,    97,
      72,   129,    72,    -1,    28,    72,     7,    72,   100,    -1,
      36,    75,     7,    57,   100,    76,    -1,     3,    -1,     4,
      -1,     8,    -1,     6,    -1,    50,   102,    31,    50,    -1,
      -1,    -1,    -1,    -1,    45,     7,   103,    75,   128,    76,
     104,    94,    31,    45,     7,   105,   102,    -1,    -1,    -1,
      -1,    33,     7,   106,    75,   128,    76,   107,    94,    31,
      33,     7,   108,   102,    -1,    -1,   116,   109,    -1,   113,
     109,    -1,   118,   109,    -1,   122,   109,    -1,    42,   109,
      -1,    32,   109,    -1,    -1,    -1,    23,     7,   110,    75,
     128,    76,   111,   109,    -1,    -1,    53,     7,   112,   109,
      -1,    -1,    -1,    37,   114,   132,    -1,    -1,    38,   115,
     132,    -1,     7,    57,   132,    -1,    -1,     7,    78,   132,
      79,   117,    57,   132,    -1,    -1,    -1,    -1,    30,   119,
     116,   120,    77,   132,   121,   137,   109,    31,    30,    -1,
      -1,    52,    75,   132,    76,   123,   124,    31,    52,    -1,
      51,   109,   125,    -1,   109,    -1,    -1,    56,   126,   109,
      -1,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
     129,    -1,    -1,   129,    77,     7,    -1,     7,    -1,    29,
      75,     3,    76,    -1,    29,    75,     1,    76,    -1,    39,
      -1,    36,    -1,    77,    39,    -1,    -1,   132,    69,   132,
      -1,   132,    70,   132,    -1,   132,    71,   132,    -1,   132,
      72,   132,    -1,    70,   132,    -1,   132,    65,   132,    -1,
     132,    66,   132,    -1,   132,    68,   132,    -1,   132,    67,
     132,    -1,   132,    64,   132,    -1,   132,    63,   132,    -1,
      -1,     7,   133,   134,    -1,     3,    -1,     4,    -1,     6,
      -1,     8,    -1,    75,   135,    76,    -1,    -1,   135,    77,
     136,    -1,   136,    -1,    -1,     3,    -1,     4,    -1,     7,
      -1,    77,     3,    -1,    77,     7,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   159,   166,   141,   185,   214,   222,   232,
     184,   242,   301,   310,   320,   242,   332,   336,   337,   338,
     339,   340,   344,   345,   346,   351,   351,   355,   368,   388,
     389,   390,   391,   395,   396,   400,   415,   416,   400,   433,
     448,   449,   433,   469,   474,   475,   476,   477,   478,   479,
     481,   492,   480,   498,   497,   503,   508,   507,   522,   521,
     538,   556,   556,   568,   574,   583,   567,   603,   602,   614,
     615,   624,   623,   636,   643,   644,   645,   646,   651,   652,
     656,   660,   668,   672,   673,   674,   678,   683,   687,   698,
     712,   723,   734,   745,   763,   781,   800,   819,   837,   856,
     855,   867,   868,   869,   870,   874,   908,   938,   939,   940,
     944,   951,   952,  1002,  1006,  1012
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGERC", "REALC", "CHARC", "LOGICALC",
  "ID", "STRINGC", "LPARENTHESIS", "RPARENTHESIS", "COMMA", "COLON",
  "CCOLON", "SEMICOLON", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE",
  "INTEGER", "REAL", "LOGICAL", "CHARACTER", "CALL", "CASE", "CLOSE",
  "CONTINUE", "CYCLE", "DATA", "DIMENSION", "DO", "END", "EXIT",
  "FUNCTION", "GOTO", "PROCEDURE", "PARAMETER", "PRINT", "PRINTLN",
  "POINTER", "PROGRAM", "RECURSIVE", "RETURN", "SELECT", "STOP",
  "SUBROUTINE", "TYPE", "PERCENT", "CONCAT", "PASSIGNMENT", "INTERFACE",
  "THEN", "IF", "READ", "COMMON", "IFX", "ELSE", "'='", "NEQV", "EQV",
  "OR", "AND", "NOT", "NE", "EQ", "GT", "GE", "LE", "LT", "'+'", "'-'",
  "'*'", "'/'", "EXP", "UMINUS", "'('", "')'", "','", "'['", "']'",
  "$accept", "program", "$@1", "$@2", "$@3", "subprogram", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "decls", "declVar",
  "optionGlob", "$@12", "optionInit", "optionDecl", "value", "declF",
  "declFunc", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "stmts",
  "$@19", "$@20", "$@21", "printStmt", "$@22", "$@23", "assignStmt",
  "$@24", "loopStmt", "$@25", "$@26", "$@27", "ifStmt", "$@28",
  "condition1", "condition2", "$@29", "types", "idn", "ids", "fAttr",
  "sAttr", "expr", "$@30", "funcCondition", "funcPara", "opt_val",
  "optionExpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    61,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,    43,
      45,    42,    47,   323,   324,    40,    41,    44,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    82,    83,    84,    81,    86,    87,    88,    89,
      85,    90,    91,    92,    93,    85,    85,    94,    94,    94,
      94,    94,    95,    95,    95,    97,    96,    98,    99,   100,
     100,   100,   100,   101,   101,   103,   104,   105,   102,   106,
     107,   108,   102,   102,   109,   109,   109,   109,   109,   109,
     110,   111,   109,   112,   109,   109,   114,   113,   115,   113,
     116,   117,   116,   119,   120,   121,   118,   123,   122,   124,
     124,   126,   125,   125,   127,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     132,   132,   132,   132,   132,   134,   134,   135,   135,   135,
     136,   136,   136,   137,   137,   137
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    12,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    15,     0,     2,     2,     2,
       2,     0,     2,     3,     6,     0,     5,     5,     6,     1,
       1,     1,     1,     4,     0,     0,     0,     0,    13,     0,
       0,     0,    13,     0,     2,     2,     2,     2,     2,     2,
       0,     0,     8,     0,     4,     0,     0,     3,     0,     3,
       3,     0,     7,     0,     0,     0,    11,     0,     8,     3,
       1,     0,     3,     0,     1,     1,     1,     1,     1,     0,
       3,     1,     4,     4,     1,     1,     2,     0,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     0,
       3,     1,     1,     1,     1,     3,     0,     3,     1,     0,
       1,     1,     1,     2,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,    21,    74,    75,    76,    77,
       0,     0,    25,    34,    21,    21,    21,    21,     0,     0,
       0,     0,    43,     3,    17,    18,    19,    20,    81,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    55,    23,
       0,    85,    84,    87,     0,     0,     0,     0,    39,    35,
       0,     0,     0,    63,    55,    56,    58,    55,     0,     0,
       0,    55,    55,    55,    55,     0,     0,     0,    80,    29,
      30,    32,    31,    27,     0,    26,     0,     0,    33,     0,
       0,    50,     0,    49,     0,     0,    48,     0,    53,     0,
      45,    44,    46,    47,     0,     0,    86,     0,    28,    79,
      79,   101,   102,   103,    99,   104,     0,    60,     0,     0,
      64,    57,    59,     0,    55,     0,    83,    82,    24,     0,
      78,     0,   106,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    79,     0,    67,    54,     4,
      40,    36,   109,   100,    98,    97,    93,    94,    96,    95,
      88,    89,    90,    91,     0,     0,     0,    55,    16,    21,
      21,   110,   111,   112,     0,   108,     0,    51,    65,    55,
      70,     0,     0,     0,     5,     0,     0,   105,     0,    62,
      55,   115,    73,     0,    11,     6,     0,     0,   107,    52,
       0,    55,    71,    69,    68,     0,     0,     0,     0,   113,
     114,     0,    55,    79,    79,    41,    37,     0,    72,     0,
       0,    43,    43,    66,    12,     7,    42,    38,    21,    21,
      13,     8,    55,    55,     0,     0,     0,     0,     0,     0,
      14,     9,    16,    16,    15,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    38,   158,   174,   196,   219,   223,   233,
     195,   218,   222,   232,    13,    14,    15,    21,    16,    17,
      73,    23,    37,    77,   160,   212,    76,   159,   211,    60,
     109,   180,   114,    61,    84,    85,    62,   154,    63,    82,
     136,   181,    64,   157,   171,   193,   202,    18,   119,   120,
      43,    67,   107,   122,   143,   164,   165,   191
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -128
static const yytype_int16 yypact[] =
{
     -30,    14,    27,  -128,  -128,    24,  -128,  -128,  -128,  -128,
     -38,   -59,  -128,    -8,    24,    24,    24,    24,     2,    48,
      52,   -15,   -25,  -128,  -128,  -128,  -128,  -128,  -128,    56,
      12,   -11,    10,    34,    56,    77,    86,    65,    97,   -11,
      26,  -128,  -128,    39,    96,    50,    50,   -47,  -128,  -128,
      67,   -39,   114,  -128,    97,  -128,  -128,    97,    43,   115,
      92,    97,    97,    97,    97,    46,    85,   112,  -128,  -128,
    -128,  -128,  -128,  -128,    55,  -128,    51,    53,  -128,    29,
      29,  -128,   126,  -128,    29,    29,  -128,    29,  -128,    98,
    -128,  -128,  -128,  -128,    61,    64,  -128,    56,  -128,    56,
      56,  -128,  -128,  -128,  -128,  -128,    29,   125,    90,    57,
    -128,   125,   125,   111,    97,   129,  -128,  -128,   -11,    66,
     -11,    68,    72,  -128,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,  -128,    56,    71,  -128,  -128,  -128,
    -128,  -128,    58,  -128,    17,    17,    17,    17,    17,    17,
       9,     9,  -128,  -128,    94,    87,    29,    60,    -7,    24,
      24,  -128,  -128,  -128,    18,  -128,    29,  -128,   125,    97,
    -128,   133,   136,   158,  -128,   135,   137,  -128,    58,   125,
      97,    93,   128,   119,  -128,  -128,   134,   140,  -128,  -128,
      16,    97,  -128,  -128,  -128,   123,   124,   179,   193,  -128,
    -128,   170,    97,    56,    56,  -128,  -128,   172,  -128,   127,
     130,   -25,   -25,  -128,  -128,  -128,  -128,  -128,    24,    24,
    -128,  -128,    97,    97,   176,   177,   178,   164,   203,   205,
    -128,  -128,    -7,    -7,  -128,  -128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,  -128,  -127,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,   -14,  -128,  -128,  -128,  -128,  -128,
     167,  -128,   -97,  -128,  -128,  -128,  -128,  -128,  -128,   -50,
    -128,  -128,  -128,  -128,  -128,  -128,   132,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,   -95,   -12,
    -128,  -128,   -56,  -128,  -128,  -128,    37,  -128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      24,    25,    26,    27,    83,   121,    31,    86,    35,    28,
       1,    90,    91,    92,    93,    29,    20,    39,    79,   199,
      36,     3,    47,   200,   108,    75,   172,     4,   111,   112,
      44,   113,   101,   102,    19,   103,   104,   105,   173,    80,
     155,    40,    22,     6,     7,     8,     9,    94,    41,    95,
     123,    42,    10,    69,    70,    32,    71,    34,    72,    33,
      11,   161,   162,    28,   138,   163,    44,    51,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    12,    30,
     132,   133,    45,    52,    48,   118,   130,   131,   132,   133,
      53,    46,    54,    49,   177,   178,    50,    55,    56,   106,
     168,    65,    57,    68,    51,   234,   235,   170,   209,   210,
     179,   169,    58,    59,   216,   217,    66,    78,    87,   182,
      52,    81,    88,    89,    96,    97,    99,    53,   100,    54,
     189,    98,   135,    51,    55,    56,   139,   116,   115,    57,
     117,   201,   140,   184,   141,   175,   176,   142,   156,    58,
      59,   166,   208,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   167,   183,   185,   186,   197,   187,   134,
     190,   194,   224,   225,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   192,   198,   205,   137,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   203,   204,
     206,   207,   213,   214,   220,   221,   215,   226,   227,   229,
     230,   228,   231,    74,   110,   188
};

static const yytype_uint8 yycheck[] =
{
      14,    15,    16,    17,    54,   100,    18,    57,    33,     7,
      40,    61,    62,    63,    64,    13,    75,    29,    57,     3,
      45,     7,    34,     7,    80,    72,    33,     0,    84,    85,
      77,    87,     3,     4,    72,     6,     7,     8,    45,    78,
     135,    29,    50,    19,    20,    21,    22,     1,    36,     3,
     106,    39,    28,     3,     4,     7,     6,    72,     8,     7,
      36,     3,     4,     7,   114,     7,    77,     7,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    54,    77,
      71,    72,    72,    23,     7,    97,    69,    70,    71,    72,
      30,    57,    32,     7,    76,    77,    31,    37,    38,    70,
     156,    75,    42,     7,     7,   232,   233,   157,   203,   204,
     166,    51,    52,    53,   211,   212,    77,    50,    75,   169,
      23,     7,     7,    31,    39,    13,    75,    30,    75,    32,
     180,    76,    75,     7,    37,    38,     7,    76,    40,    42,
      76,   191,    76,     7,    76,   159,   160,    75,    77,    52,
      53,    57,   202,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    76,    31,     7,    31,    33,    31,    79,
      77,    52,   222,   223,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    56,    45,     7,    76,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    75,    75,
       7,    31,    30,    76,   218,   219,    76,    31,    31,    45,
       7,    33,     7,    46,    82,   178
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    81,     7,     0,    82,    19,    20,    21,    22,
      28,    36,    54,    94,    95,    96,    98,    99,   127,    72,
      75,    97,    50,   101,    94,    94,    94,    94,     7,    13,
      77,   129,     7,     7,    72,    33,    45,   102,    83,   129,
      29,    36,    39,   130,    77,    72,    57,   129,     7,     7,
      31,     7,    23,    30,    32,    37,    38,    42,    52,    53,
     109,   113,   116,   118,   122,    75,    77,   131,     7,     3,
       4,     6,     8,   100,   100,    72,   106,   103,    50,    57,
      78,     7,   119,   109,   114,   115,   109,    75,     7,    31,
     109,   109,   109,   109,     1,     3,    39,    13,    76,    75,
      75,     3,     4,     6,     7,     8,    70,   132,   132,   110,
     116,   132,   132,   132,   112,    40,    76,    76,   129,   128,
     129,   128,   133,   132,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    79,    75,   120,    76,   109,     7,
      76,    76,    75,   134,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   117,   128,    77,   123,    84,   107,
     104,     3,     4,     7,   135,   136,    57,    76,   132,    51,
     109,   124,    33,    45,    85,    94,    94,    76,    77,   132,
     111,   121,   109,    31,     7,     7,    31,    31,   136,   109,
      77,   137,    56,   125,    52,    90,    86,    33,    45,     3,
       7,   109,   126,    75,    75,     7,     7,    31,   109,   128,
     128,   108,   105,    30,    76,    76,   102,   102,    91,    87,
      94,    94,    92,    88,   109,   109,    31,    31,    33,    45,
       7,     7,    93,    89,    85,    85
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 142 "y.y"
    {   //Main program
		  scope *sc = createScope();
		  symTable *s;
		  scopeGroup[scopeNum++] = sc;
		  currentScope = sc;
		  sc -> prevLink = globalScope;
		  s = insert(currentScope, (yyvsp[(2) - (2)].sval));
		  s->type = PROG_TYPE;

		  className = strdup((yyvsp[(2) - (2)].sval));
		  file = fopen("output.jasm", "w");
		  fprintf(file, "class %s\n", className);
		  fprintf(file, "{\n");
			
	  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 159 "y.y"
    {
		  fprintf(file, "\tmethod public static void main(java.lang.String[])\n");
		  fprintf(file, "\tmax_stack 15\n");
		  fprintf(file, "\tmax_locals 15\n");
		  fprintf(file, "\t{\n");
	  ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 166 "y.y"
    {
		  if(strcmp((yyvsp[(2) - (10)].sval), (yyvsp[(10) - (10)].sval)) != 0) 
			  yyerror("Variable name(program) doesn't match.");

		  fprintf(file, "\t\treturn\n");
		  fprintf(file, "\t}\n");
		    
	  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 176 "y.y"
    {

		  fprintf(file, "}\n");
	  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 185 "y.y"
    {     //subroutine body
		    int i, end;
			symTable *s;
	    
			for(i = 0; i < funcNum; i++)
			{
				if(strcmp((yyvsp[(2) - (2)].sval), funcAry[i]->mSym->name) == 0)
				{
					tempFunc = funcAry[i];
					break;
				}
			}
	    
			if(i == funcNum) yyerror("Subroutine not declear.");

			end = tempFunc->varNum;
			for(i = 0; i < end; ++i)
			{
				table[i] = tempFunc->var[i];
			}
	    
			vCurrent = end;
			prevScope = currentScope;
			currentScope = tempFunc->link;
			scopeGroup[scopeNum++] = currentScope;
			currentScope->prevLink = globalScope;
			funcCons = 1;
			
	  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 214 "y.y"
    {
		    if(varNum != tempFunc->varNum)
				yyerror("Function variable num not correct."); 

			varNum = 0;
	  	  	funcCons = 0; 
			funcDecl = 1;
	  ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 222 "y.y"
    {
		    int i;
		    for(i = 0; i < vCurrent; i++)
			    if(table[i] != NULL)
				    yyerror("Function variable type not decleard."); 
	  		
			varNum = 0; 
			funcDecl = 0;
	  ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 232 "y.y"
    {
		    int i;
	  		if(strcmp((yyvsp[(2) - (13)].sval), (yyvsp[(13) - (13)].sval)) != 0)
				yyerror("Variable name(subroutine) doesn't match.");
			
			vCurrent = 0;
			
	  ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 242 "y.y"
    { //function body
		    int i;
		    int end;
			symTable *s;
			char *type;
			
			for(i = 0; i < funcNum; i++)
			{
				if(strcmp((yyvsp[(2) - (2)].sval), funcAry[i]->mSym->name) == 0)
				{
					tempFunc = funcAry[i];
					break;
				}
			}
			
			if(i == funcNum) yyerror("Function not declear.");
			
			end = tempFunc->varNum;
			for(i = 0; i < end; ++i)
				table[i] = tempFunc->var[i];

			table[i] = s;

			vCurrent = end + 1;
			
			prevScope = currentScope;
			currentScope = tempFunc->link;
			scopeGroup[scopeNum++] = currentScope;
			currentScope->prevLink = globalScope;
			s = insert(currentScope, (yyvsp[(2) - (2)].sval));
			funcCons = 1;

			if(tempFunc->mSym->type == INT_TYPE)
				type = "int";
			else if(tempFunc->mSym->type == REAL_TYPE)
				type = "float";
			
			fprintf(file, "\tmethod public static %s %s(",
					type,
					tempFunc->mSym->name);

			for(i = 0; i < tempFunc->varNum; i++)
            {
	            if(tempFunc->var[i]->type == INT_TYPE)
		            type = "int";
	            else if(tempFunc->var[i]->type == REAL_TYPE)
		            type = "float";
				
	            if(i != 0)
		            fprintf(file, ", %s", type);
	            else
		            fprintf(file, "%s", type);
            }
            fprintf(file, ")\n");
			fprintf(file, "\tmax_stack 15\n");
			fprintf(file, "\tmax_locals 15\n\t{\n");
			
					
	  ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 301 "y.y"
    {
 	  	  	if(varNum != tempFunc->varNum)
				yyerror("Function variable num not correct."); 

			varNum = 0;
	  	  	funcCons = 0; 
			funcDecl = 1;
	  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 310 "y.y"
    {
		  int i;
		  for(i = 0; i < vCurrent; i++)
			  if(table[i] != NULL)
				  yyerror("Function variable type not decleard."); 
	  		
		  varNum = 0; 
		  funcDecl = 0;
	  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 320 "y.y"
    {
		  symTable *s = search(currentScope, (yyvsp[(13) - (13)].sval));
		  
		  if(strcmp((yyvsp[(2) - (13)].sval), (yyvsp[(13) - (13)].sval)) != 0) 
			  yyerror("Variable name(subroutine) doesn't match.");
		  vCurrent = 0;

		  fprintf(file, "\t\tiload %d\n", s->index);
		  fprintf(file, "\t\tireturn\n");
		  fprintf(file, "\t}\n");
	  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 336 "y.y"
    {vCurrent = 0;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 344 "y.y"
    {aTemp = ERR_ATTR;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 345 "y.y"
    {aTemp = ERR_ATTR;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 346 "y.y"
    {aTemp = ERR_ATTR;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 351 "y.y"
    {globalVa = 1;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 351 "y.y"
    {globalVa = 0;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 357 "y.y"
    {
	  		int i = 0;
			symTable *s;
			for(;i < vCurrent; i++)
				if(strcmp((yyvsp[(3) - (5)].sval), table[i]->name) == 0) break;
			if(i == vCurrent) yyerror("Global variable declear not find.");
			if(s->type != tempType) yyerror("Init value type not match.");
	  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 369 "y.y"
    {
	  	  	symTable *s = search(currentScope, (yyvsp[(3) - (6)].sval));
			if(s == NULL) 
				yyerror("(parameter)Variable is not exist.");
			if(s->attr != PARA_ATTR) 
				yyerror("(parameter)This variable hasn't parameter attribute.");
	  	    if(tempType != s->type)
			    yyerror("(parameter)const not the same type.");

		    if(s->type == INT_TYPE)
			    s->ival = tempInt;
		    else if(s->type == REAL_TYPE)
			    s->dval = tempReal;
		    else if(s->type == CHAR_TYPE)
			    s->sval = strdup(tempStr);		
	   ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 388 "y.y"
    {tempType = INT_TYPE; tempInt = (yyvsp[(1) - (1)].ival);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 389 "y.y"
    {tempType = REAL_TYPE; tempReal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 390 "y.y"
    {tempType = CHAR_TYPE; tempStr = (yyvsp[(1) - (1)].sval);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 391 "y.y"
    {tempType = LOGI_TYPE; tempBool = (yyvsp[(1) - (1)].bval);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 400 "y.y"
    {
			scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(currentScope, (yyvsp[(2) - (2)].sval));
			s = insert(sc, (yyvsp[(2) - (2)].sval));
			if(s == NULL) yyerror("function ID wasn't exist.");
			s->type = SUBR_TYPE;
			tTemp = SUBR_TYPE;

			func *f = createFunc();
			f->mSym = s;
			f->link = sc;
			funcAry[funcNum] = f;

	  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 415 "y.y"
    {funcVaType = 1;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 416 "y.y"
    {

		    int i;
			symTable *s = search(currentScope, (yyvsp[(11) - (11)].sval));
			for(i = 0; i < vCurrent; i++)
			{
				if(table[i] != NULL) yyerror("Variable type not declear.");
			}
	  	    if(strcmp((yyvsp[(2) - (11)].sval), (yyvsp[(11) - (11)].sval)) != 0) yyerror("Subroutine's name doesn't match.");

			vCurrent = 0;
			funcVaType = 0;
			funcNum++;
			
	  ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 433 "y.y"
    {
	  		scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(currentScope, (yyvsp[(2) - (2)].sval));
			s = insert(sc, (yyvsp[(2) - (2)].sval));
			if(s == NULL) yyerror("ID wasn't exist.");
			table[vCurrent++] = s;
			tTemp = FUNC_TYPE;

			func *f = createFunc();
			f->mSym = s;
			f->link = sc;
			funcAry[funcNum] = f;
			inFunc = 1;
	  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 448 "y.y"
    {funcVaType = 1;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 449 "y.y"
    {
            symTable *s = search(tempScope, (yyvsp[(11) - (11)].sval));
	  		int i;
			for(i = 0; i < vCurrent; i++)
				if(table[i] != NULL) yyerror("Variable type not declear.");
				
			if(strcmp((yyvsp[(2) - (11)].sval),(yyvsp[(11) - (11)].sval)) != 0) yyerror("Function's name doesn't match.");

			for(i = 0; i < funcAry[funcNum]->varNum; i++)
			{
				funcAry[funcNum]->var[i]->index = i;
			}

			s->index = funcAry[funcNum]->varNum;
			
			vCurrent = 0;
			funcVaType = 0;
			funcNum++;
	  ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 481 "y.y"
    {
	  	    symTable *s = search(currentScope, (yyvsp[(2) - (2)].sval));
			if(s == NULL)
				yyerror("Subroutine CALL was not exist.");
			if(s->type != SUBR_TYPE)
				yyerror("Subroutine type error.");

			funcName = (yyvsp[(2) - (2)].sval);
			subrCall = 1;
	  ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 492 "y.y"
    {
		    subrCall = 0;
		    varNum = 0;
	  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 498 "y.y"
    {
	  	    symTable *s = search(currentScope, (yyvsp[(2) - (2)].sval));
			if(s == NULL) yyerror("Function CALL was not exist.");
	  ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 508 "y.y"
    {
		  fprintf(file, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
	  ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 512 "y.y"
    {
		  char *type;
		  if((yyvsp[(3) - (3)].epty)->type == INT_TYPE)
			  type = "int";
		  else if((yyvsp[(3) - (3)].epty)->type == CHAR_TYPE)
			  type = "java.lang.String";
				  
		  fprintf(file, "\t\tinvokevirtual void java.io.PrintStream.print(%s)\n", type);
	  ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 522 "y.y"
    {
		  fprintf(file, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
	  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 526 "y.y"
    {
		  char *type;
		  if((yyvsp[(3) - (3)].epty)->type == INT_TYPE)
			  type = "int";
		  else if((yyvsp[(3) - (3)].epty)->type == CHAR_TYPE)
			  type = "java.lang.String";
				  
		  fprintf(file, "\t\tinvokevirtual void java.io.PrintStream.println(%s)\n", type);
	  ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 538 "y.y"
    {
	  	 	symTable *s = searchRecu(currentScope, (yyvsp[(1) - (3)].sval));
			
			if(s == NULL) yyerror("Assign id wasn't exist.");
			if(s->type == (yyvsp[(3) - (3)].epty)->type){}
			else yyerror("Assign Expression type error.");

			if(s->attr == BOTH || s->attr == PARA_ATTR)
				yyerror("This Id is CONST can't be assign.");

			if(search(currentScope, (yyvsp[(1) - (3)].sval)) != NULL)
				fprintf(file, "\t\tistore %d\n", s->index);
			else
				fprintf(file, "\t\tputstatic int %s.%s\n", className, (yyvsp[(1) - (3)].sval));

			if(isLoopAss == 1)
				incV = s;
	  ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 556 "y.y"
    {
	  	 	if((yyvsp[(3) - (4)].epty)->type != INT_TYPE) yyerror("Assign Exp Type error.");
	  ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 559 "y.y"
    {
	 	 	symTable *s = search(currentScope, (yyvsp[(1) - (7)].sval));
			if(s == NULL) yyerror("Assign Exp id doesn't exist.");
			if(s->type != (yyvsp[(7) - (7)].epty)->type) yyerror("Assign Exp type not match.");
	  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 568 "y.y"
    {
		  loopifNum++;
		  isLoop = 1;
		  isLoopAss = 1;
	  ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 574 "y.y"
    {
		  int index = loopifNum*2;
		  tempIndex = index+1;
		  labelStack[index] = labelNum;
		  isLoopAss = 0;
		  fprintf(file, "\tL%d:\n", labelNum++);
		  
	  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 583 "y.y"
    {
		  if((yyvsp[(6) - (6)].epty)->type != LOGI_TYPE)
			  yyerror("(Loop)If exp type error.");
	  ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 588 "y.y"
    {
		  int index = loopifNum*2-2;
		  fprintf(file, "\t\tsipush %d\n", inc);
		  fprintf(file, "\t\tiload %d\n", incV->index);
		  fprintf(file, "\t\tiadd\n");
		  fprintf(file, "\t\tistore %d\n", incV->index);
		  fprintf(file, "\t\tgoto L%d\n", index);
		  fprintf(file, "\tL%d:\n", index+1);
		  isLoop = 0;
		  loopifNum--;
	  ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 603 "y.y"
    {
		  if((yyvsp[(3) - (4)].epty)->type != LOGI_TYPE)yyerror("If expr type error.");
		  loopifNum++;
	  ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 608 "y.y"
    {
		  loopifNum--;
	  ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 616 "y.y"
    {
		  int index = loopifNum*2-2;
		  fprintf(file, "\tL%d:\n", index);
	  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 624 "y.y"
    {
		  int index = loopifNum*2-2;
		  labelStack[tempIndex] = labelNum;
		  fprintf(file, "\t\tgoto L%d\n", labelNum++);
		  fprintf(file, "\tL%d:\n",  index);
	  ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 631 "y.y"
    {
		  int index = loopifNum*2-1;
		  fprintf(file, "\tL%d:\n", index);
	  ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 636 "y.y"
    {
		  int index = loopifNum*2-2;
		  fprintf(file, "\tL%d:\n", index);
	  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 643 "y.y"
    {tTemp = 1;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 644 "y.y"
    {tTemp = 2;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 645 "y.y"
    {tTemp = 3;;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 646 "y.y"
    {tTemp = 4;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 656 "y.y"
    { 
		idCondition((yyvsp[(3) - (3)].sval));
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 660 "y.y"
    {
		idCondition((yyvsp[(1) - (1)].sval));
	  ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 668 "y.y"
    {
	  	  	aTemp = ARY_ATTR;
		  	dimesParam = (yyvsp[(3) - (4)].ival);
		  	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 673 "y.y"
    {aTemp = PTR_ATTR;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 674 "y.y"
    {aTemp = PARA_ATTR;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 679 "y.y"
    {
	  	    if(aTemp != ARY_ATTR) yyerror("Same Attribute Decleared.");
	  	  	aTemp = BOTH;
	  ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 688 "y.y"
    {
	  	    if( arithmeticCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == ERR_TYPE ) 
				yyerror("Arithmetic + TYPE Error.");
			else if( arithmeticCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == REAL_TYPE )
				(yyval.epty) = expGenerate(REAL_TYPE);
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\tiadd\n");
	  ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 699 "y.y"
    { 
	  	   	Types t = arithmeticCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty));
	  	    if(t == ERR_TYPE) 
				yyerror("Arithmetic - TYPE Error.");
			else if(t == REAL_TYPE )
			{
				(yyval.epty) = expGenerate(REAL_TYPE);
			}
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\tisub\n");
	  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 713 "y.y"
    { 
	  	    if( arithmeticCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == ERR_TYPE) 
				yyerror("Arithmetic * TYPE Error.");
			else if( arithmeticCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == REAL_TYPE )
				(yyval.epty) = expGenerate(REAL_TYPE);
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\timul\n");
	  ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 724 "y.y"
    { 
	  	    if( arithmeticCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == ERR_TYPE) 
				yyerror("Arithmetic // TYPE Error.");
			else if( arithmeticCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == REAL_TYPE )
				(yyval.epty) = expGenerate(REAL_TYPE);
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\tidiv\n");
	  ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 735 "y.y"
    {
	  	  	if( (yyvsp[(2) - (2)].epty)->type != INT_TYPE && (yyvsp[(2) - (2)].epty)->type != REAL_TYPE)
				yyerror("unary TYPE not match.");
			if((yyvsp[(2) - (2)].epty)->type == INT_TYPE)
				(yyval.epty) = expGenerate(INT_TYPE);
			else
				(yyval.epty) = expGenerate(REAL_TYPE);

			fprintf(file, "\t\tineg\n");
	  ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 746 "y.y"
    {
		    if( expTypeCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == 0)
				yyerror("Relation expression TYPE Error.");
			(yyval.epty) = expGenerate(LOGI_TYPE);

			int index;
			if(isLoop == 1)
				index = tempIndex;
			else
			{
				index = loopifNum*2;
				tempIndex = index+1;
			}
			labelStack[index] = labelNum;
			fprintf(file, "\t\tisub\n");
			fprintf(file, "\t\tifle L%d\n", labelNum++);
	  ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 764 "y.y"
    {
		    if( expTypeCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == 0)
				yyerror("Relation expression TYPE Error.");
			(yyval.epty) = expGenerate(LOGI_TYPE);

			int index;
			if(isLoop == 1)
				index = tempIndex;
			else
			{
				index = loopifNum*2;
				tempIndex = index+1;
			}
			labelStack[index] = labelNum;
			fprintf(file, "\t\tisub\n");
			fprintf(file, "\t\tiflt L%d\n", labelNum++);
	  ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 782 "y.y"
    {
	  	   
		    if( expTypeCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == 0)
				yyerror("Relation expression TYPE Error.");
			(yyval.epty) = expGenerate(LOGI_TYPE);

			int index;
			if(isLoop == 1)
				index = tempIndex;
			else
			{
				index = loopifNum*2;
				tempIndex = index+1;
			}
		    labelStack[index] = labelNum;
	  		fprintf(file, "\t\tisub\n");
			fprintf(file, "\t\tifge L%d\n", labelNum++);
	  ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 801 "y.y"
    {
		
		    if( expTypeCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == 0)
				yyerror("Relation expression TYPE Error.");
			(yyval.epty) = expGenerate(LOGI_TYPE);

			int index;
			if(isLoop == 1)
				index = tempIndex;
			else
			{
				index = loopifNum*2;
				tempIndex = index+1;
			}
		    labelStack[index] = labelNum;
			fprintf(file, "\t\tisub\n");
			fprintf(file, "\t\tifgt L%d\n", labelNum++);
	  ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 820 "y.y"
    {
		    if( expTypeCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == 0)
				yyerror("Relation expression TYPE Error.");
			(yyval.epty) = expGenerate(LOGI_TYPE);

			int index;
			if(isLoop == 1)
				index = tempIndex;
			else
			{
				index = loopifNum*2;
				tempIndex = index+1;
			}
		    labelStack[index] = labelNum;
			fprintf(file, "\t\tisub\n");
			fprintf(file, "\t\tifgt L%d\n", labelNum++);
	  ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 838 "y.y"
    {
		    if( expTypeCheck((yyvsp[(1) - (3)].epty), (yyvsp[(3) - (3)].epty)) == 0)
				yyerror("Relation expression TYPE Error.");
			(yyval.epty) = expGenerate(LOGI_TYPE);

			int index;
			if(isLoop == 1)
				index = tempIndex;
			else
			{
				index = loopifNum*2;
				tempIndex = index+1;
			}
		    labelStack[index] = labelNum;
			fprintf(file, "\t\tisub\n");
			fprintf(file, "\t\tifgt L%d\n", labelNum++);
	  ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 856 "y.y"
    {
		  funcName = (yyvsp[(1) - (1)].sval);
	  ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 861 "y.y"
    {
	        symTable *s = searchRecu(currentScope, (yyvsp[(1) - (3)].sval));
			if(s == NULL) yyerror("This id doesn't exist.");
	  	    (yyval.epty) = expGenerate(s->type);
	  ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 867 "y.y"
    {(yyval.epty) = expGenerate(INT_TYPE); fprintf(file, "\t\tsipush %d\n", (yyvsp[(1) - (1)].ival));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 868 "y.y"
    {(yyval.epty) = expGenerate(REAL_TYPE); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 869 "y.y"
    {(yyval.epty) = expGenerate(LOGI_TYPE); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 870 "y.y"
    {(yyval.epty) = expGenerate(CHAR_TYPE); ;fprintf(file, "\t\tldc \"%s\"\n", (yyvsp[(1) - (1)].sval));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 875 "y.y"
    {
		    int i;
		    char *type;
		    symTable *s = search(currentScope, funcName);
			
            if(varNum != tempFunc->varNum)
	            yyerror("Function parameter num was not corrent.");
            
            varNum = 0;
            funcCall = 0;
			
            if(s->type == INT_TYPE)
				type = "int";
			else if(s->type == REAL_TYPE)
				type = "float";
			else yyerror("(Function call) type error.");

            fprintf(file, "\t\tinvokestatic %s %s.%s(", type, className, funcName);
            for(i = 0; i < tempFunc->varNum; i++)
            {
	            if(tempFunc->var[i]->type == INT_TYPE)
		            type = "int";
	            else if(tempFunc->var[i]->type == REAL_TYPE)
		            type = "float";
				
	            if(i != 0)
		            fprintf(file, ", %s", type);
	            else
		            fprintf(file, "%s", type);
            }
            fprintf(file, ")\n");
      ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 908 "y.y"
    {
		    symTable *s = searchRecu(currentScope, funcName);
			char *type;

			if(s->attr == PARA_ATTR)
			{
				if(s->type == INT_TYPE)
					fprintf(file, "\t\tsipush %d\n", s->ival);
				else if(s->type == CHAR_TYPE)
					fprintf(file, "\t\tldc \"%s\"\n", s->sval);
			}
			else
			{
				if(s->type == INT_TYPE)
					type = strdup("int");
				else if(s->type == REAL_TYPE)
					type = strdup("float");
				else yyerror("(Function call) type error.");
			
				if(search(currentScope, funcName) != NULL)
					fprintf(file, "\t\tiload %d\n", s->index);
				else
					fprintf(file, "\t\tgetstaitc %s %s.%s\n", type, className, s->name);
			}

		
      ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 945 "y.y"
    {
		  tempType = INT_TYPE;
		  varNum++;

		  fprintf(file, "\t\tsipush %d\n", (yyvsp[(1) - (1)].ival));
	  ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 951 "y.y"
    {tempType = REAL_TYPE;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 953 "y.y"
    {
		  int i;
		  symTable *s = searchRecu(currentScope, (yyvsp[(1) - (1)].sval));
		  if(s == NULL) yyerror("id not in this scope.");

		  for(i = 0; i < funcNum; i++)
		  {
			  if(strcmp(funcName, funcAry[i]->mSym->name) == 0)
			  {
				  tempFunc = funcAry[i];
				  break;
			  }
		  }
		  if(i == funcNum) yyerror("Subroutine not declear.");
		    

		  if(s->type != tempFunc->var[varNum]->type)
			  yyerror("Function call variable type not match.");

		  varNum++;

		  if(search(currentScope, (yyvsp[(1) - (1)].sval)) != NULL)
		  {
			  if(s->attr == PARA_ATTR)
			  {
				  if(s->type == INT_TYPE)
					  fprintf(file, "\t\t sipush %d\n", s->ival);
				  else if(s->type == CHAR_TYPE)
					  fprintf(file, "\t\t ldc \"%s\"\n", s->sval);
			  }
			  else
				  fprintf(file, "\t\tiload %d\n", s->index);
		  }
		  else
		  {
			  if(s->attr == PARA_ATTR)
			  {
				  if(s->type == INT_TYPE)
					  fprintf(file, "\t\t sipush %d\n", s->ival);
				  else if(s->type == CHAR_TYPE)
					  fprintf(file, "\t\t ldc \"%s\"\n", s->sval);
			  }
			  else	  
			  fprintf(file, "\t\tgetstatic int %s.%s\n", className, (yyvsp[(1) - (1)].sval));
		  }
      ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1003 "y.y"
    {
		  inc = (yyvsp[(2) - (2)].ival);
	  ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1006 "y.y"
    { 
	  	    symTable *s = search(currentScope, (yyvsp[(2) - (2)].sval));
			if(s->type != INT_TYPE && s->type != REAL_TYPE) 
				yyerror("optional expr type error.");
	  ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1012 "y.y"
    {
		  inc = 1;
	  ;}
    break;



/* Line 1455 of yacc.c  */
#line 2911 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1017 "y.y"


int main(int argc, char *argv[])
{
	int i;

	tempFunc = NULL;
	scopeNum = 0;
	for(i = 0;i < 10;i++){
		table[i] = NULL;
	}
	tempScope = NULL;
	tempSym = NULL;
	tempType =ERR_TYPE;

	prevScope = NULL;
	globalScope = createScope();
	globalScope->prevLink = NULL;
	scopeGroup[scopeNum++] = globalScope;
		

	yyparse();

	for(i = 0; i < scopeNum; i++)
	{
		printf("var num : %d\n", scopeGroup[i]->varNum);
		dump(scopeGroup[i]);
	}

	return 0;
}

Types arithmeticCheck(expType *e1, expType *e2)
{
	if(e1->type == INT_TYPE && e2->type == INT_TYPE)
		return INT_TYPE;
	else if(e1->type == REAL_TYPE && e2->type == REAL_TYPE)
		return REAL_TYPE;
	else if(e1->type == INT_TYPE && e2->type == REAL_TYPE)
		return REAL_TYPE;
	else if(e1->type == REAL_TYPE && e2->type == INT_TYPE)
		return REAL_TYPE;
	else
		return ERR_TYPE;
}


int isIntOrReal(Types t)
{
	if(t == INT_TYPE || t == REAL_TYPE)
		return 1;
	else
		return -1;
}

expType* expGenerate(Types t)
{
	expType *e;
	MALLOC(e, sizeof(expType));
	e->type = t;
	return e;
}

int expTypeCheck(expType *e1, expType *e2)
{
	if(e1->type != e2->type)
		return 0;
	else
		return 1;
}

func* createFunc()
{
	func *f;
	MALLOC(f, sizeof(func));
	f->varNum = 0;
	return f;
}

void idCondition(char *idToken)
{
	if(funcCall == 1)
	{
		int i;
		symTable *s = searchRecu(currentScope, idToken);
		if(s == NULL) yyerror("id not in this scope.");
		for(i = 0; i < funcNum; i++)
		{
			if(strcmp(funcName, funcAry[i]->mSym->name) == 0)
			{
				tempFunc = funcAry[i];
				break;
			}
		}
		if(i == funcNum) yyerror("Subroutine not declear.");

		if(s->type != tempFunc->var[varNum]->type)
			yyerror("Function call variable type not match.");

		varNum++;
	}
	else if(subrCall == 1)
	{
		int i;
		symTable *s = searchRecu(currentScope, idToken);
		if(s == NULL) yyerror("Subroutine's parameter not exist.");
		for(i = 0; i < funcNum; i++)
		{
			if(strcmp(funcName, funcAry[i]->mSym->name) == 0)
			{
				tempFunc = funcAry[i];
				break;
			}
		}
		if(i == funcNum) yyerror("Subroutine not declear.");

		if(s->type != tempFunc->var[varNum]->type)
			yyerror("subroutine call variable type not match.");

		varNum++;
	}	
	else if(globalVa == 1)
	{
		symTable *s1 = search(currentScope, idToken);
		symTable *s2;

		if(s1 == NULL)
			yyerror("This variable not exist in this scope.");

		s2 = insert(globalScope, idToken);
		
		if(s2 == NULL)
			yyerror("ID was existed in global.");
		
		s2->type = s1->type;
		s2->attr = s1->attr;
		
		deleteSym(currentScope, s1);

		if(s2->type == INT_TYPE)
			fprintf(file, "\tfield static int %s\n", idToken);
		else if(s2->type == REAL_TYPE)
			fprintf(file, "\tfield static float %s\n", idToken);
		
	}
	else if(funcCons == 1)
	{		
		int i;
		int end = tempFunc->varNum;
		if(strcmp(idToken, tempFunc->var[varNum]->name) != 0)
			yyerror("Function decleard(parameter) not match.");

		varNum++;
	}
	else if(funcDecl == 1)
	{
		int i;
		int end = tempFunc->varNum;
		
		symTable *s = insert(currentScope, idToken);

		if(s == NULL) {
			for(i = 0; i < end; i++)
			{
				
				if(table[i] != NULL)
				{
					if(strcmp(idToken, table[i]->name)==0)
					{
						if(tTemp == table[i]->type)
						{
							table[i] = NULL;
						}
						else
							yyerror("(Function)Variable type declear error.");
					}
				}
			}
		}
		else
		{
			s->type = tTemp;
			s->attr = aTemp;
		}
	}
	else if(funcVaType == 1)
	{
		int i;
		symTable *s;
		for(i = 0; i < vCurrent; i++)
		{
			if(table[i] != NULL)
			{
				s = table[i];
				if(strcmp(idToken, s->name) == 0) break;
			}
		}

		if(i == vCurrent) yyerror("Variable not declear.");
		s->type = tTemp;
		s->attr = aTemp;
		table[i] = NULL;
	}	
	else if(tTemp == FUNC_TYPE || tTemp == SUBR_TYPE)
	{
		symTable *s = insert(tempScope, idToken);
		func *f = funcAry[funcNum];
		if(s == NULL) yyerror("ID name was exist.");
		table[vCurrent++] = s;
		f->var[(f->varNum)++] = s;
	}
	else
	{			
		symTable *s = insert(currentScope, idToken);
		if(s == NULL) yyerror("ID name was exist");
		s->type = tTemp;
		s->attr = aTemp;
	}

}

