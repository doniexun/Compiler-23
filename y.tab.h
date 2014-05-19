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
    LPARENTHESIS = 263,
    RPARENTHESIS = 264,
    COMMA = 265,
    COLON = 266,
    CCOLON = 267,
    SEMICOLON = 268,
    LBRACKET = 269,
    RBRACKET = 270,
    LBRACE = 271,
    RBRACE = 272,
    INTEGER = 273,
    REAL = 274,
    LOGICAL = 275,
    CHARACTER = 276,
    CALL = 277,
    CASE = 278,
    CLOSE = 279,
    CONTINUE = 280,
    CYCLE = 281,
    DATA = 282,
    DIMENSION = 283,
    DO = 284,
    ELSE = 285,
    END = 286,
    EXIT = 287,
    FUNCTION = 288,
    GOTO = 289,
    IF = 290,
    PROCEDURE = 291,
    PARAMETER = 292,
    PRINT = 293,
    PRINTLN = 294,
    POINTER = 295,
    PROGRAM = 296,
    RECURSIVE = 297,
    RETURN = 298,
    SELECT = 299,
    STOP = 300,
    SUBROUTINE = 301,
    TYPE = 302,
    PERCENT = 303,
    CONCAT = 304,
    PASSIGNMENT = 305,
    INTERFACE = 306,
    EQV = 307,
    NEQV = 308,
    OR = 309,
    AND = 310,
    NOT = 311,
    LT = 312,
    LE = 313,
    GE = 314,
    GT = 315,
    EQ = 316,
    NE = 317,
    EXP = 318,
    UMINUS = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 34 "y.y" /* yacc.c:1909  */

	int ival;
	float dval;
	char cval;
	int bval;
	struct expType *epty;
	char *sval;
	symTable *sym; // ID or INTEGERC or REALC

#line 129 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
