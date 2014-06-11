/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "y.y" /* yacc.c:339  */

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

#line 147 "y.tab.c" /* yacc.c:339  */

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
    EQV = 312,
    NEQV = 313,
    OR = 314,
    AND = 315,
    NOT = 316,
    LT = 317,
    LE = 318,
    GE = 319,
    GT = 320,
    EQ = 321,
    NE = 322,
    EXP = 323,
    UMINUS = 324
  };
#endif
/* Tokens.  */
#define INTEGERC 258
#define REALC 259
#define CHARC 260
#define LOGICALC 261
#define ID 262
#define STRINGC 263
#define LPARENTHESIS 264
#define RPARENTHESIS 265
#define COMMA 266
#define COLON 267
#define CCOLON 268
#define SEMICOLON 269
#define LBRACKET 270
#define RBRACKET 271
#define LBRACE 272
#define RBRACE 273
#define INTEGER 274
#define REAL 275
#define LOGICAL 276
#define CHARACTER 277
#define CALL 278
#define CASE 279
#define CLOSE 280
#define CONTINUE 281
#define CYCLE 282
#define DATA 283
#define DIMENSION 284
#define DO 285
#define END 286
#define EXIT 287
#define FUNCTION 288
#define GOTO 289
#define PROCEDURE 290
#define PARAMETER 291
#define PRINT 292
#define PRINTLN 293
#define POINTER 294
#define PROGRAM 295
#define RECURSIVE 296
#define RETURN 297
#define SELECT 298
#define STOP 299
#define SUBROUTINE 300
#define TYPE 301
#define PERCENT 302
#define CONCAT 303
#define PASSIGNMENT 304
#define INTERFACE 305
#define THEN 306
#define IF 307
#define READ 308
#define COMMON 309
#define IFX 310
#define ELSE 311
#define EQV 312
#define NEQV 313
#define OR 314
#define AND 315
#define NOT 316
#define LT 317
#define LE 318
#define GE 319
#define GT 320
#define EQ 321
#define NE 322
#define EXP 323
#define UMINUS 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 82 "y.y" /* yacc.c:355  */

	int ival;
	float dval;
	char cval;
	int bval;
	struct expType *epty;
	char *sval;
	symTable *sym; // ID or INTEGERC or REALC

#line 335 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 350 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   161,   168,   141,   187,   216,   224,   234,
     186,   244,   303,   312,   322,   244,   334,   338,   339,   340,
     341,   342,   346,   347,   348,   353,   353,   357,   370,   390,
     391,   392,   393,   397,   398,   402,   417,   418,   402,   435,
     450,   451,   435,   471,   476,   477,   478,   479,   480,   481,
     483,   494,   482,   500,   499,   505,   510,   509,   524,   523,
     540,   558,   558,   570,   576,   585,   569,   605,   604,   616,
     617,   626,   625,   638,   645,   646,   647,   648,   653,   654,
     658,   662,   670,   674,   675,   676,   680,   685,   689,   700,
     714,   725,   736,   747,   765,   783,   802,   821,   839,   858,
     857,   869,   870,   871,   872,   876,   910,   940,   941,   942,
     946,   953,   954,  1004,  1008,  1014
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "THEN", "IF", "READ", "COMMON", "IFX", "ELSE", "'='", "EQV", "NEQV",
  "OR", "AND", "NOT", "LT", "LE", "GE", "GT", "EQ", "NE", "'+'", "'-'",
  "'*'", "'/'", "EXP", "UMINUS", "'('", "')'", "','", "'['", "']'",
  "$accept", "program", "$@1", "$@2", "$@3", "subprogram", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "decls", "declVar",
  "optionGlob", "$@12", "optionInit", "optionDecl", "value", "declF",
  "declFunc", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "stmts",
  "$@19", "$@20", "$@21", "printStmt", "$@22", "$@23", "assignStmt",
  "$@24", "loopStmt", "$@25", "$@26", "$@27", "ifStmt", "$@28",
  "condition1", "condition2", "$@29", "types", "idn", "ids", "fAttr",
  "sAttr", "expr", "$@30", "funcCondition", "funcPara", "opt_val",
  "optionExpr", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    61,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,    43,
      45,    42,    47,   323,   324,    40,    41,    44,    91,    93
};
# endif

#define YYPACT_NINF -128

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-128)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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
      40,    36,   109,   100,    95,    96,    94,    93,    97,    98,
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
        case 2:
#line 142 "y.y" /* yacc.c:1646  */
    {   //Main program
		  scope *sc = createScope();
		  symTable *s;
		  scopeGroup[scopeNum++] = sc;
		  currentScope = sc;
		  sc -> prevLink = globalScope;
		  s = insert(currentScope, (yyvsp[0].sval));
		  s->type = PROG_TYPE;
		  
		  if(className == NULL)
			  className = strdup((yyvsp[0].sval));
		  
		  file = fopen("output.jasm", "w");
		  fprintf(file, "class %s\n", className);
		  fprintf(file, "{\n");
			
	  }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 161 "y.y" /* yacc.c:1646  */
    {
		  fprintf(file, "\tmethod public static void main(java.lang.String[])\n");
		  fprintf(file, "\tmax_stack 15\n");
		  fprintf(file, "\tmax_locals 15\n");
		  fprintf(file, "\t{\n");
	  }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "y.y" /* yacc.c:1646  */
    {
		  if(strcmp((yyvsp[-8].sval), (yyvsp[0].sval)) != 0) 
			  yyerror("Variable name(program) doesn't match.");

		  fprintf(file, "\t\treturn\n");
		  fprintf(file, "\t}\n");
		    
	  }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 178 "y.y" /* yacc.c:1646  */
    {

		  fprintf(file, "}\n");
	  }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 187 "y.y" /* yacc.c:1646  */
    {     //subroutine body
		    int i, end;
			symTable *s;
	    
			for(i = 0; i < funcNum; i++)
			{
				if(strcmp((yyvsp[0].sval), funcAry[i]->mSym->name) == 0)
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
			
	  }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 216 "y.y" /* yacc.c:1646  */
    {
		    if(varNum != tempFunc->varNum)
				yyerror("Function variable num not correct."); 

			varNum = 0;
	  	  	funcCons = 0; 
			funcDecl = 1;
	  }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 224 "y.y" /* yacc.c:1646  */
    {
		    int i;
		    for(i = 0; i < vCurrent; i++)
			    if(table[i] != NULL)
				    yyerror("Function variable type not decleard."); 
	  		
			varNum = 0; 
			funcDecl = 0;
	  }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 234 "y.y" /* yacc.c:1646  */
    {
		    int i;
	  		if(strcmp((yyvsp[-11].sval), (yyvsp[0].sval)) != 0)
				yyerror("Variable name(subroutine) doesn't match.");
			
			vCurrent = 0;
			
	  }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 244 "y.y" /* yacc.c:1646  */
    { //function body
		    int i;
		    int end;
			symTable *s;
			char *type;
			
			for(i = 0; i < funcNum; i++)
			{
				if(strcmp((yyvsp[0].sval), funcAry[i]->mSym->name) == 0)
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
			s = insert(currentScope, (yyvsp[0].sval));
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
			
					
	  }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 303 "y.y" /* yacc.c:1646  */
    {
 	  	  	if(varNum != tempFunc->varNum)
				yyerror("Function variable num not correct."); 

			varNum = 0;
	  	  	funcCons = 0; 
			funcDecl = 1;
	  }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 312 "y.y" /* yacc.c:1646  */
    {
		  int i;
		  for(i = 0; i < vCurrent; i++)
			  if(table[i] != NULL)
				  yyerror("Function variable type not decleard."); 
	  		
		  varNum = 0; 
		  funcDecl = 0;
	  }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 322 "y.y" /* yacc.c:1646  */
    {
		  symTable *s = search(currentScope, (yyvsp[0].sval));
		  
		  if(strcmp((yyvsp[-11].sval), (yyvsp[0].sval)) != 0) 
			  yyerror("Variable name(subroutine) doesn't match.");
		  vCurrent = 0;

		  fprintf(file, "\t\tiload %d\n", s->index);
		  fprintf(file, "\t\tireturn\n");
		  fprintf(file, "\t}\n");
	  }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 338 "y.y" /* yacc.c:1646  */
    {vCurrent = 0;}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 346 "y.y" /* yacc.c:1646  */
    {aTemp = ERR_ATTR;}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 347 "y.y" /* yacc.c:1646  */
    {aTemp = ERR_ATTR;}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 348 "y.y" /* yacc.c:1646  */
    {aTemp = ERR_ATTR;}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 353 "y.y" /* yacc.c:1646  */
    {globalVa = 1;}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 353 "y.y" /* yacc.c:1646  */
    {globalVa = 0;}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 359 "y.y" /* yacc.c:1646  */
    {
	  		int i = 0;
			symTable *s;
			for(;i < vCurrent; i++)
				if(strcmp((yyvsp[-2].sval), table[i]->name) == 0) break;
			if(i == vCurrent) yyerror("Global variable declear not find.");
			if(s->type != tempType) yyerror("Init value type not match.");
	  }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 371 "y.y" /* yacc.c:1646  */
    {
	  	  	symTable *s = search(currentScope, (yyvsp[-3].sval));
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
	   }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 390 "y.y" /* yacc.c:1646  */
    {tempType = INT_TYPE; tempInt = (yyvsp[0].ival);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 391 "y.y" /* yacc.c:1646  */
    {tempType = REAL_TYPE; tempReal = (yyvsp[0].dval);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 392 "y.y" /* yacc.c:1646  */
    {tempType = CHAR_TYPE; tempStr = (yyvsp[0].sval);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 393 "y.y" /* yacc.c:1646  */
    {tempType = LOGI_TYPE; tempBool = (yyvsp[0].bval);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 402 "y.y" /* yacc.c:1646  */
    {
			scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(currentScope, (yyvsp[0].sval));
			s = insert(sc, (yyvsp[0].sval));
			if(s == NULL) yyerror("function ID wasn't exist.");
			s->type = SUBR_TYPE;
			tTemp = SUBR_TYPE;

			func *f = createFunc();
			f->mSym = s;
			f->link = sc;
			funcAry[funcNum] = f;

	  }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 417 "y.y" /* yacc.c:1646  */
    {funcVaType = 1;}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 418 "y.y" /* yacc.c:1646  */
    {

		    int i;
			symTable *s = search(currentScope, (yyvsp[0].sval));
			for(i = 0; i < vCurrent; i++)
			{
				if(table[i] != NULL) yyerror("Variable type not declear.");
			}
	  	    if(strcmp((yyvsp[-9].sval), (yyvsp[0].sval)) != 0) yyerror("Subroutine's name doesn't match.");

			vCurrent = 0;
			funcVaType = 0;
			funcNum++;
			
	  }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 435 "y.y" /* yacc.c:1646  */
    {
	  		scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(currentScope, (yyvsp[0].sval));
			s = insert(sc, (yyvsp[0].sval));
			if(s == NULL) yyerror("ID wasn't exist.");
			table[vCurrent++] = s;
			tTemp = FUNC_TYPE;

			func *f = createFunc();
			f->mSym = s;
			f->link = sc;
			funcAry[funcNum] = f;
			inFunc = 1;
	  }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 450 "y.y" /* yacc.c:1646  */
    {funcVaType = 1;}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 451 "y.y" /* yacc.c:1646  */
    {
            symTable *s = search(tempScope, (yyvsp[0].sval));
	  		int i;
			for(i = 0; i < vCurrent; i++)
				if(table[i] != NULL) yyerror("Variable type not declear.");
				
			if(strcmp((yyvsp[-9].sval),(yyvsp[0].sval)) != 0) yyerror("Function's name doesn't match.");

			for(i = 0; i < funcAry[funcNum]->varNum; i++)
			{
				funcAry[funcNum]->var[i]->index = i;
			}

			s->index = funcAry[funcNum]->varNum;
			
			vCurrent = 0;
			funcVaType = 0;
			funcNum++;
	  }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 483 "y.y" /* yacc.c:1646  */
    {
	  	    symTable *s = search(currentScope, (yyvsp[0].sval));
			if(s == NULL)
				yyerror("Subroutine CALL was not exist.");
			if(s->type != SUBR_TYPE)
				yyerror("Subroutine type error.");

			funcName = (yyvsp[0].sval);
			subrCall = 1;
	  }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 494 "y.y" /* yacc.c:1646  */
    {
		    subrCall = 0;
		    varNum = 0;
	  }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 500 "y.y" /* yacc.c:1646  */
    {
	  	    symTable *s = search(currentScope, (yyvsp[0].sval));
			if(s == NULL) yyerror("Function CALL was not exist.");
	  }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 510 "y.y" /* yacc.c:1646  */
    {
		  fprintf(file, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
	  }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 514 "y.y" /* yacc.c:1646  */
    {
		  char *type;
		  if((yyvsp[0].epty)->type == INT_TYPE)
			  type = "int";
		  else if((yyvsp[0].epty)->type == CHAR_TYPE)
			  type = "java.lang.String";
				  
		  fprintf(file, "\t\tinvokevirtual void java.io.PrintStream.print(%s)\n", type);
	  }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 524 "y.y" /* yacc.c:1646  */
    {
		  fprintf(file, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
	  }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 528 "y.y" /* yacc.c:1646  */
    {
		  char *type;
		  if((yyvsp[0].epty)->type == INT_TYPE)
			  type = "int";
		  else if((yyvsp[0].epty)->type == CHAR_TYPE)
			  type = "java.lang.String";
				  
		  fprintf(file, "\t\tinvokevirtual void java.io.PrintStream.println(%s)\n", type);
	  }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 540 "y.y" /* yacc.c:1646  */
    {
	  	 	symTable *s = searchRecu(currentScope, (yyvsp[-2].sval));
			
			if(s == NULL) yyerror("Assign id wasn't exist.");
			if(s->type == (yyvsp[0].epty)->type){}
			else yyerror("Assign Expression type error.");

			if(s->attr == BOTH || s->attr == PARA_ATTR)
				yyerror("This Id is CONST can't be assign.");

			if(search(currentScope, (yyvsp[-2].sval)) != NULL)
				fprintf(file, "\t\tistore %d\n", s->index);
			else
				fprintf(file, "\t\tputstatic int %s.%s\n", className, (yyvsp[-2].sval));

			if(isLoopAss == 1)
				incV = s;
	  }
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 558 "y.y" /* yacc.c:1646  */
    {
	  	 	if((yyvsp[-1].epty)->type != INT_TYPE) yyerror("Assign Exp Type error.");
	  }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 561 "y.y" /* yacc.c:1646  */
    {
	 	 	symTable *s = search(currentScope, (yyvsp[-6].sval));
			if(s == NULL) yyerror("Assign Exp id doesn't exist.");
			if(s->type != (yyvsp[0].epty)->type) yyerror("Assign Exp type not match.");
	  }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 570 "y.y" /* yacc.c:1646  */
    {
		  loopifNum++;
		  isLoop = 1;
		  isLoopAss = 1;
	  }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 576 "y.y" /* yacc.c:1646  */
    {
		  int index = loopifNum*2;
		  tempIndex = index+1;
		  labelStack[index] = labelNum;
		  isLoopAss = 0;
		  fprintf(file, "\tL%d:\n", labelNum++);
		  
	  }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 585 "y.y" /* yacc.c:1646  */
    {
		  if((yyvsp[0].epty)->type != LOGI_TYPE)
			  yyerror("(Loop)If exp type error.");
	  }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 590 "y.y" /* yacc.c:1646  */
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
	  }
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 605 "y.y" /* yacc.c:1646  */
    {
		  if((yyvsp[-1].epty)->type != LOGI_TYPE)yyerror("If expr type error.");
		  loopifNum++;
	  }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 610 "y.y" /* yacc.c:1646  */
    {
		  loopifNum--;
	  }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 618 "y.y" /* yacc.c:1646  */
    {
		  int index = loopifNum*2-2;
		  fprintf(file, "\tL%d:\n", index);
	  }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 626 "y.y" /* yacc.c:1646  */
    {
		  int index = loopifNum*2-2;
		  labelStack[tempIndex] = labelNum;
		  fprintf(file, "\t\tgoto L%d\n", labelNum++);
		  fprintf(file, "\tL%d:\n",  index);
	  }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 633 "y.y" /* yacc.c:1646  */
    {
		  int index = loopifNum*2-1;
		  fprintf(file, "\tL%d:\n", index);
	  }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 638 "y.y" /* yacc.c:1646  */
    {
		  int index = loopifNum*2-2;
		  fprintf(file, "\tL%d:\n", index);
	  }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 645 "y.y" /* yacc.c:1646  */
    {tTemp = 1;}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 646 "y.y" /* yacc.c:1646  */
    {tTemp = 2;}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 647 "y.y" /* yacc.c:1646  */
    {tTemp = 3;}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 648 "y.y" /* yacc.c:1646  */
    {tTemp = 4;}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 658 "y.y" /* yacc.c:1646  */
    { 
		idCondition((yyvsp[0].sval));
	}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 662 "y.y" /* yacc.c:1646  */
    {
		idCondition((yyvsp[0].sval));
	  }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 670 "y.y" /* yacc.c:1646  */
    {
	  	  	aTemp = ARY_ATTR;
		  	dimesParam = (yyvsp[-1].ival);
		  	}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 675 "y.y" /* yacc.c:1646  */
    {aTemp = PTR_ATTR;}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 676 "y.y" /* yacc.c:1646  */
    {aTemp = PARA_ATTR;}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 681 "y.y" /* yacc.c:1646  */
    {
	  	    if(aTemp != ARY_ATTR) yyerror("Same Attribute Decleared.");
	  	  	aTemp = BOTH;
	  }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 690 "y.y" /* yacc.c:1646  */
    {
	  	    if( arithmeticCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == ERR_TYPE ) 
				yyerror("Arithmetic + TYPE Error.");
			else if( arithmeticCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == REAL_TYPE )
				(yyval.epty) = expGenerate(REAL_TYPE);
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\tiadd\n");
	  }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 701 "y.y" /* yacc.c:1646  */
    { 
	  	   	Types t = arithmeticCheck((yyvsp[-2].epty), (yyvsp[0].epty));
	  	    if(t == ERR_TYPE) 
				yyerror("Arithmetic - TYPE Error.");
			else if(t == REAL_TYPE )
			{
				(yyval.epty) = expGenerate(REAL_TYPE);
			}
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\tisub\n");
	  }
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 715 "y.y" /* yacc.c:1646  */
    { 
	  	    if( arithmeticCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == ERR_TYPE) 
				yyerror("Arithmetic * TYPE Error.");
			else if( arithmeticCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == REAL_TYPE )
				(yyval.epty) = expGenerate(REAL_TYPE);
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\timul\n");
	  }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 726 "y.y" /* yacc.c:1646  */
    { 
	  	    if( arithmeticCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == ERR_TYPE) 
				yyerror("Arithmetic // TYPE Error.");
			else if( arithmeticCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == REAL_TYPE )
				(yyval.epty) = expGenerate(REAL_TYPE);
			else
				(yyval.epty) = expGenerate(INT_TYPE);

			fprintf(file, "\t\tidiv\n");
	  }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 737 "y.y" /* yacc.c:1646  */
    {
	  	  	if( (yyvsp[0].epty)->type != INT_TYPE && (yyvsp[0].epty)->type != REAL_TYPE)
				yyerror("unary TYPE not match.");
			if((yyvsp[0].epty)->type == INT_TYPE)
				(yyval.epty) = expGenerate(INT_TYPE);
			else
				(yyval.epty) = expGenerate(REAL_TYPE);

			fprintf(file, "\t\tineg\n");
	  }
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 748 "y.y" /* yacc.c:1646  */
    {
		    if( expTypeCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == 0)
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
	  }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 766 "y.y" /* yacc.c:1646  */
    {
		    if( expTypeCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == 0)
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
	  }
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 784 "y.y" /* yacc.c:1646  */
    {
	  	   
		    if( expTypeCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == 0)
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
	  }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 803 "y.y" /* yacc.c:1646  */
    {
		
		    if( expTypeCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == 0)
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
	  }
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 822 "y.y" /* yacc.c:1646  */
    {
		    if( expTypeCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == 0)
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
	  }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 840 "y.y" /* yacc.c:1646  */
    {
		    if( expTypeCheck((yyvsp[-2].epty), (yyvsp[0].epty)) == 0)
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
	  }
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 858 "y.y" /* yacc.c:1646  */
    {
		  funcName = (yyvsp[0].sval);
	  }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 863 "y.y" /* yacc.c:1646  */
    {
	        symTable *s = searchRecu(currentScope, (yyvsp[-2].sval));
			if(s == NULL) yyerror("This id doesn't exist.");
	  	    (yyval.epty) = expGenerate(s->type);
	  }
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 869 "y.y" /* yacc.c:1646  */
    {(yyval.epty) = expGenerate(INT_TYPE); fprintf(file, "\t\tsipush %d\n", (yyvsp[0].ival));}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 870 "y.y" /* yacc.c:1646  */
    {(yyval.epty) = expGenerate(REAL_TYPE); }
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 871 "y.y" /* yacc.c:1646  */
    {(yyval.epty) = expGenerate(LOGI_TYPE); }
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 872 "y.y" /* yacc.c:1646  */
    {(yyval.epty) = expGenerate(CHAR_TYPE); ;fprintf(file, "\t\tldc \"%s\"\n", (yyvsp[0].sval));}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 877 "y.y" /* yacc.c:1646  */
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
      }
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 910 "y.y" /* yacc.c:1646  */
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

		
      }
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 947 "y.y" /* yacc.c:1646  */
    {
		  tempType = INT_TYPE;
		  varNum++;

		  fprintf(file, "\t\tsipush %d\n", (yyvsp[0].ival));
	  }
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 953 "y.y" /* yacc.c:1646  */
    {tempType = REAL_TYPE;}
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 955 "y.y" /* yacc.c:1646  */
    {
		  int i;
		  symTable *s = searchRecu(currentScope, (yyvsp[0].sval));
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

		  if(search(currentScope, (yyvsp[0].sval)) != NULL)
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
			  fprintf(file, "\t\tgetstatic int %s.%s\n", className, (yyvsp[0].sval));
		  }
      }
#line 2703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1005 "y.y" /* yacc.c:1646  */
    {
		  inc = (yyvsp[0].ival);
	  }
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1008 "y.y" /* yacc.c:1646  */
    { 
	  	    symTable *s = search(currentScope, (yyvsp[0].sval));
			if(s->type != INT_TYPE && s->type != REAL_TYPE) 
				yyerror("optional expr type error.");
	  }
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1014 "y.y" /* yacc.c:1646  */
    {
		  inc = 1;
	  }
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2733 "y.tab.c" /* yacc.c:1646  */
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
#line 1019 "y.y" /* yacc.c:1906  */


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

	className = NULL;

	if(argc > 1)
		className = argv[1];

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
