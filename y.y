%{
#include "symTable.h"
#include "lex.yy.c"
//#include "operator.h"

struct expType {
	char *name;
	Types type;
	int ival;
	float dval;
	char cval;
	int bval;
};

void yyerror (char const *s);
extern int yylex(void);

//Types checkType(enum operator, Types, Types);
int isIntOrReal(Types a);

Types tTemp;
int dimesParam;
Attrs aTemp;

%}



%union{
	int ival;
	float dval;
	char cval;
	int bval;
	struct expType *epty;
	char *sval;
	symTable *sym; // ID or INTEGERC or REALC
};


%token <ival> INTEGERC
%token <dval> REALC
%token <cval> CHARC
%token <bval> LOGICALC
%token <sval> ID

%token LPARENTHESIS
%token RPARENTHESIS
%token COMMA
%token COLON
%token CCOLON
%token SEMICOLON
%token LBRACKET
%token RBRACKET
%token LBRACE
%token RBRACE

%token INTEGER
%token REAL
%token LOGICAL
%token CHARACTER

%token CALL CASE CLOSE CONTINUE CYCLE DATA DIMENSION DO ELSE END EXIT FUNCTION
       GOTO IF PROCEDURE PARAMETER PRINT PRINTLN POINTER PROGRAM RECURSIVE
       RETURN SELECT STOP SUBROUTINE TYPE PERCENT CONCAT PASSIGNMENT

%right '='
%left EQV NEQV
%left OR
%left AND
%left NOT
%left LT LE GE GT EQ NE
%left '+' '-'
%left '*' '/'
%left EXP
%nonassoc UMINUS

%type <epty> expr
%%
program
	: PROGRAM ID '\n' 
	  		{ 
	  		printf("accept\n");
			symTable *s = insert(currentScope, $2);
			s->type = PROG_TYPE;
			}

	  context END PROGRAM ID '\n' 
	  		{
	  	   	printf("program : %s\n", $8);
	  	    if(strcmp($2, $8) != 0) yyerror("Varible name(program) doens't match.");
			}
	;

context
	: decls exprs
	;

decls
	: declVar decls '\n'
	| declFunc decls '\n'
    |
	;

declVar
	: types ids {aTemp = ERR_ATTR;}
	| types CCOLON ids {aTemp = ERR_ATTR;}
	| types ',' fAttr sAttr CCOLON ids {aTemp = ERR_ATTR;}
    ;

declFunc
    : INTERFACE ;

exprs
	: expr exprs '\n'
	| 
	;
			   
types
	: INTEGER   {tTemp = 1;}
   	| REAL	    {tTemp = 2;}
    | LOGICAL   {tTemp = 3;}
    | CHARACTER {tTemp = 4;}
	;

ids
	: ids ',' ID {
			symTable *s = insert(currentScope, $3);
	  	  	if(s == NULL) yyerror("ID name was exist");
	  	  	else {
				s->type = tTemp;
				s->attr = aTemp;
			}
			}
	| ID    {
			symTable *s = insert(currentScope, $1);
	  	  	if(s == NULL) yyerror("ID name was exist");
	  	  	else {
				s->type = tTemp;
				s->attr = aTemp;
			}
			}
	;

fAttr
	: DIMENSION '(' INTEGERC ')' {
	  	  	aTemp = ARY_ATTR;
		  	dimesParam = $3;
		  	}
    | POINTER   {aTemp = PTR_ATTR;}
	| PARAMETER {aTemp = PARA_ATTR;}
    ;

sAttr
	: ',' POINTER {
	  	    if(aTemp != ARY_ATTR) yyerror("Same Attribute Decleared.");
	  	  	aTemp = BOTH;
			}
	|
	;

expr
	: expr '+' expr 
	| expr '-' expr 
	| expr '*' expr
	| expr '/' expr
	| ID
	| INTEGERC
	| REALC
	| CHARC
	| LOGICALC
	;


%%

int main(int argc, char *argv[])
{
	currentScope = createScope();

yyparse();
return 0;
}

void yyerror (const char const *s) {
   fprintf (stderr, "%s\n", s);
   exit(EXIT_FAILURE);
}

int isIntOrReal(Types a)
{
	if(a == 1)
		return 1;
	else if(a == 2)
		return 2;
	else if(a == 0)
		return 0;
	else return -1;
}
