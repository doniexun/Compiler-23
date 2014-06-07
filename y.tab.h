/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 77 "y.y" /* yacc.c:1909  */

	int ival;
	float dval;
	char cval;
	int bval;
	struct expType *epty;
	char *sval;
	symTable *sym; // ID or INTEGERC or REALC

#line 134 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
