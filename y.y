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

scope *tempScope;


symTable *table[10];
int vCurrent = 0;

int typeDef = 0;
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
       RETURN SELECT STOP SUBROUTINE TYPE PERCENT CONCAT PASSIGNMENT INTERFACE

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
	: PROGRAM ID
	  		{ 
	  		printf("accept\n");
			symTable *s = insert(currentScope, $2);
			s->type = PROG_TYPE;
			}

	  context END PROGRAM ID 
	  		{
	  	   	printf("program : %s\n", $7);
	  	    if(strcmp($2, $7) != 0) yyerror("Varible name(program) doens't match.");
			}
	;

context
	: decls exprs
	;

decls
	: declVar decls
	| declFunc decls
    |
	;

declVar
	: types ids {aTemp = ERR_ATTR;}
	| types CCOLON ids {aTemp = ERR_ATTR;}
	| types ',' fAttr sAttr CCOLON ids {aTemp = ERR_ATTR;}
    ;

declFunc
	: INTERFACE SUBROUTINE ID {
			scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(sc, $3);
			if(s == NULL) yyerror("ID was exist.");
			s->type = SUBR_TYPE;
			tTemp = SUBR_TYPE;
	  }
	  '(' idn ')' {	
	  	  	  typeDef = 1;
			  int i;
			  printf("vCurrent:%d\n", vCurrent);
	  	  	  for(i = 0; i < vCurrent; i++)
			  {
				  printf("token %s\n", table[i]->name);
			  }
			}
	  decls END SUBROUTINE ID {
	  		int i;
			for(i = 0; i < vCurrent; i++)
			{
				if(table[i] != NULL) yyerror("Variable type not declear.");
			}
	  	    if(strcmp($3, $12) != 0) yyerror("Subroutine's name doesn't match.");
			vCurrent = 0;
			typeDef = 0;
	  }

	| INTERFACE FUNCTION ID {
	  		scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(sc, $3);
			if(s == NULL) yyerror("ID was exist.");
			table[vCurrent++] = s;
			tTemp = FUNC_TYPE;
			}
	  '(' idn ')' {	typeDef = 1; }
	  decls END FUNCTION ID {
	  		int i;
			for(i = 0; i < vCurrent; i++)
				if(table[i] != NULL) yyerror("Variable type not declear.");
				
			if(strcmp($3,$12) != 0) yyerror("Function's name doesn't match.");
			vCurrent = 0;
			typeDef = 0;		
	  }
	;



exprs
	: expr exprs 
	| 
	;
			   
types
	: INTEGER   {tTemp = 1;}
   	| REAL	    {tTemp = 2;}
    | LOGICAL   {tTemp = 3;}
    | CHARACTER {tTemp = 4;}
	;


idn
	: ids
	| 
	;

ids
	: ids ',' ID { 
	  	  	if(typeDef == 0)
			{
				if(tTemp == FUNC_TYPE || tTemp == SUBR_TYPE)
				{
					symTable *s = insert(tempScope, $3);
					if(s == NULL) yyerror("ID name was exist.");
					table[vCurrent++] = s;
				}
				else
				{			
					symTable *s = insert(currentScope, $3);
	  	  			if(s == NULL) yyerror("ID name was exist");
					s->type = tTemp;
					s->attr = aTemp;
				}
			}
			else
			{
				int i = 0;
				symTable *s;
				for(i = 0; i < vCurrent; i++)
				{
					if(table[i] != NULL)
					{
						s = table[i];
						if(strcmp($3, s->name) == 0) break;
					}
				}

				if(i == vCurrent) yyerror("Variable not declear.");
				s->type = tTemp;
				s->attr = aTemp;
				table[i] = NULL;
			}
	  }

	| ID {
			if(typeDef == 0)
			{
				if(tTemp == FUNC_TYPE || tTemp == SUBR_TYPE)
				{
					symTable *s = insert(tempScope, $1);
					if(s == NULL) yyerror("ID name was exist.");
					table[vCurrent++] = s;
				}
				else
				{			
					symTable *s = insert(currentScope, $1);
	  	  			if(s == NULL) yyerror("ID name was exist");
					s->type = tTemp;
					s->attr = aTemp;
				}
			}
			else
			{
				int i = 0;
				symTable *s;
				for(i = 0; i < vCurrent; i++)
				{
					if(table[i] != NULL)
					{
						s = table[i];
						if(strcmp($1, s->name) == 0) break;
					}
				}

				if(i == vCurrent) yyerror("Variable not declear.");
				s->type = tTemp;
				s->attr = aTemp;
				table[i] = NULL;

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
	int i = 0;
	for(;i < 10;i++){
		table[i] = NULL;
		tempTable[i] = NULL;
	}
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
