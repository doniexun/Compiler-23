%{
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
%token <sval> STRINGC

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

%token CALL CASE CLOSE CONTINUE CYCLE DATA DIMENSION DO END EXIT FUNCTION
       GOTO PROCEDURE PARAMETER PRINT PRINTLN POINTER PROGRAM RECURSIVE
       RETURN SELECT STOP SUBROUTINE TYPE PERCENT CONCAT PASSIGNMENT INTERFACE
	   THEN IF READ COMMON

%nonassoc IFX
%right THEN
%right ELSE


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
	  {   //Main program
		  scope *sc = createScope();
		  symTable *s;
		  scopeGroup[scopeNum++] = sc;
		  currentScope = sc;
		  sc -> prevLink = globalScope;
		  s = insert(currentScope, $2);
		  s->type = PROG_TYPE;

		  className = strdup($2);
		  file = fopen("output.jasm", "w");
		  fprintf(file, "class %s\n", className);
		  fprintf(file, "{\n");
			
	  }

	  decls declF
	  {
		  fprintf(file, "\tmethod public static void main(java.lang.String[])\n");
		  fprintf(file, "\tmax_stack 15\n");
		  fprintf(file, "\tmax_locals 15\n");
		  fprintf(file, "\t{\n");
	  }
	  stmts END PROGRAM ID
	  {
		  if(strcmp($2, $10) != 0) 
			  yyerror("Variable name(program) doesn't match.");

		  fprintf(file, "\t\treturn\n");
		  fprintf(file, "\t}\n");
		    
	  }

	  subprogram 
      {

		  fprintf(file, "}\n");
	  }
	
	;

subprogram
	: SUBROUTINE ID 
	  {     //subroutine body
		    int i, end;
			symTable *s;
	    
			for(i = 0; i < funcNum; i++)
			{
				if(strcmp($2, funcAry[i]->mSym->name) == 0)
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
	  '(' idn ')' {
		    if(varNum != tempFunc->varNum)
				yyerror("Function variable num not correct."); 

			varNum = 0;
	  	  	funcCons = 0; 
			funcDecl = 1;
	  }
	  decls {
		    int i;
		    for(i = 0; i < vCurrent; i++)
			    if(table[i] != NULL)
				    yyerror("Function variable type not decleard."); 
	  		
			varNum = 0; 
			funcDecl = 0;
	  }

	  stmts END SUBROUTINE ID {
		    int i;
	  		if(strcmp($2, $13) != 0)
				yyerror("Variable name(subroutine) doesn't match.");
			
			vCurrent = 0;
			
	  } 
	  subprogram
			
	| FUNCTION ID { //function body
		    int i;
		    int end;
			symTable *s;
			char *type;
			
			for(i = 0; i < funcNum; i++)
			{
				if(strcmp($2, funcAry[i]->mSym->name) == 0)
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
			s = insert(currentScope, $2);
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
	  '(' idn ')' {
 	  	  	if(varNum != tempFunc->varNum)
				yyerror("Function variable num not correct."); 

			varNum = 0;
	  	  	funcCons = 0; 
			funcDecl = 1;
	  }
	  decls
	  {
		  int i;
		  for(i = 0; i < vCurrent; i++)
			  if(table[i] != NULL)
				  yyerror("Function variable type not decleard."); 
	  		
		  varNum = 0; 
		  funcDecl = 0;
	  }
	  stmts END FUNCTION ID
	  {
		  symTable *s = search(currentScope, $13);
		  
		  if(strcmp($2, $13) != 0) 
			  yyerror("Variable name(subroutine) doesn't match.");
		  vCurrent = 0;

		  fprintf(file, "\t\tiload %d\n", s->index);
		  fprintf(file, "\t\tireturn\n");
		  fprintf(file, "\t}\n");
	  }
	  subprogram
    | 
	;

decls
    : declVar decls {vCurrent = 0;}
	| optionGlob decls
	| optionInit decls
	| optionDecl decls
	| 
	;

declVar
	: types ids {aTemp = ERR_ATTR;}
	| types CCOLON ids {aTemp = ERR_ATTR;}
	| types ',' fAttr sAttr CCOLON ids {aTemp = ERR_ATTR;}
    ;


optionGlob
	: COMMON {globalVa = 1;} '/' ids '/' {globalVa = 0;}
	;

optionInit
	: DATA '/' ID '/' value
   
	  {
	  		int i = 0;
			symTable *s;
			for(;i < vCurrent; i++)
				if(strcmp($3, table[i]->name) == 0) break;
			if(i == vCurrent) yyerror("Global variable declear not find.");
			if(s->type != tempType) yyerror("Init value type not match.");
	  }
	;

optionDecl
	: PARAMETER '(' ID '=' value ')'
	  {
	  	  	symTable *s = search(currentScope, $3);
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
	;

value
    : INTEGERC {tempType = INT_TYPE; tempInt = $1;}
    | REALC    {tempType = REAL_TYPE; tempReal = $1;}
    | STRINGC  {tempType = CHAR_TYPE; tempStr = $1;}
    | LOGICALC {tempType = LOGI_TYPE; tempBool = $1;}
	;

declF
    : INTERFACE declFunc END INTERFACE
    | 
    ;

declFunc
	: SUBROUTINE ID {
			scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(currentScope, $2);
			s = insert(sc, $2);
			if(s == NULL) yyerror("function ID wasn't exist.");
			s->type = SUBR_TYPE;
			tTemp = SUBR_TYPE;

			func *f = createFunc();
			f->mSym = s;
			f->link = sc;
			funcAry[funcNum] = f;

	  }
	  '(' idn ')' {funcVaType = 1;}
	  decls END SUBROUTINE ID {

		    int i;
			symTable *s = search(currentScope, $11);
			for(i = 0; i < vCurrent; i++)
			{
				if(table[i] != NULL) yyerror("Variable type not declear.");
			}
	  	    if(strcmp($2, $11) != 0) yyerror("Subroutine's name doesn't match.");

			vCurrent = 0;
			funcVaType = 0;
			funcNum++;
			
	  }
	  declFunc

	| FUNCTION ID {
	  		scope *sc = createScope();
			tempScope = sc;	
	  		symTable *s = insert(currentScope, $2);
			s = insert(sc, $2);
			if(s == NULL) yyerror("ID wasn't exist.");
			table[vCurrent++] = s;
			tTemp = FUNC_TYPE;

			func *f = createFunc();
			f->mSym = s;
			f->link = sc;
			funcAry[funcNum] = f;
			inFunc = 1;
	  }
	  '(' idn ')' {funcVaType = 1;}
	  decls END FUNCTION ID {
            symTable *s = search(tempScope, $11);
	  		int i;
			for(i = 0; i < vCurrent; i++)
				if(table[i] != NULL) yyerror("Variable type not declear.");
				
			if(strcmp($2,$11) != 0) yyerror("Function's name doesn't match.");

			for(i = 0; i < funcAry[funcNum]->varNum; i++)
			{
				funcAry[funcNum]->var[i]->index = i;
			}

			s->index = funcAry[funcNum]->varNum;
			
			vCurrent = 0;
			funcVaType = 0;
			funcNum++;
	  }
	  declFunc
	| 
	;


stmts
	: assignStmt stmts
	| printStmt stmts
	| loopStmt  stmts
	| ifStmt stmts
	| RETURN  stmts
	| EXIT  stmts
	| CALL ID 
	  {
	  	    symTable *s = search(currentScope, $2);
			if(s == NULL)
				yyerror("Subroutine CALL was not exist.");
			if(s->type != SUBR_TYPE)
				yyerror("Subroutine type error.");

			funcName = $2;
			subrCall = 1;
	  }
	  '(' idn ')' 
	  {
		    subrCall = 0;
		    varNum = 0;
	  }
      stmts 
	| READ ID 
	  {
	  	    symTable *s = search(currentScope, $2);
			if(s == NULL) yyerror("Function CALL was not exist.");
	  }
	  stmts
	| 
	;

printStmt
	: PRINT
	  {
		  fprintf(file, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
	  }
	  expr
	  {
		  char *type;
		  if($3->type == INT_TYPE)
			  type = "int";
		  else if($3->type == CHAR_TYPE)
			  type = "java.lang.String";
				  
		  fprintf(file, "\t\tinvokevirtual void java.io.PrintStream.print(%s)\n", type);
	  }
	| PRINTLN
	  {
		  fprintf(file, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
	  }
      expr
	  {
		  char *type;
		  if($3->type == INT_TYPE)
			  type = "int";
		  else if($3->type == CHAR_TYPE)
			  type = "java.lang.String";
				  
		  fprintf(file, "\t\tinvokevirtual void java.io.PrintStream.println(%s)\n", type);
	  }
	;

assignStmt
	: ID '=' expr {
	  	 	symTable *s = searchRecu(currentScope, $1);
			
			if(s == NULL) yyerror("Assign id wasn't exist.");
			if(s->type == $3->type){}
			else yyerror("Assign Expression type error.");

			if(s->attr == BOTH || s->attr == PARA_ATTR)
				yyerror("This Id is CONST can't be assign.");

			if(search(currentScope, $1) != NULL)
				fprintf(file, "\t\tistore %d\n", s->index);
			else
				fprintf(file, "\t\tputstatic int %s.%s\n", className, $1);

			if(isLoopAss == 1)
				incV = s;
	  }
	| ID '[' expr ']' {
	  	 	if($3->type != INT_TYPE) yyerror("Assign Exp Type error.");
	  }
	 '=' expr {
	 	 	symTable *s = search(currentScope, $1);
			if(s == NULL) yyerror("Assign Exp id doesn't exist.");
			if(s->type != $7->type) yyerror("Assign Exp type not match.");
	  }
	;

loopStmt
	: DO
	  {
		  loopifNum++;
		  isLoop = 1;
		  isLoopAss = 1;
	  }
	  assignStmt
	  {
		  int index = loopifNum*2;
		  tempIndex = index+1;
		  labelStack[index] = labelNum;
		  isLoopAss = 0;
		  fprintf(file, "\tL%d:\n", labelNum++);
		  
	  }
      ',' expr
	  {
		  if($6->type != LOGI_TYPE)
			  yyerror("(Loop)If exp type error.");
	  }
	  optionExpr stmts END DO
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
	;

ifStmt
	: IF '(' expr ')'
	  {
		  if($3->type != LOGI_TYPE)yyerror("If expr type error.");
		  loopifNum++;
	  }
      condition1 END IF
	  {
		  loopifNum--;
	  }
	;

condition1
	: THEN stmts condition2
	| stmts
 	  {
		  int index = loopifNum*2-2;
		  fprintf(file, "\tL%d:\n", index);
	  }
	;

condition2
	: ELSE
	  {
		  int index = loopifNum*2-2;
		  labelStack[tempIndex] = labelNum;
		  fprintf(file, "\t\tgoto L%d\n", labelNum++);
		  fprintf(file, "\tL%d:\n",  index);
	  }
      stmts
	  {
		  int index = loopifNum*2-1;
		  fprintf(file, "\tL%d:\n", index);
	  }
	| 
	  {
		  int index = loopifNum*2-2;
		  fprintf(file, "\tL%d:\n", index);
	  }
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
		idCondition($3);
	}

	| ID {
		idCondition($1);
	  }
	;



fAttr
	: DIMENSION '(' INTEGERC ')' {
	  	  	aTemp = ARY_ATTR;
		  	dimesParam = $3;
		  	}
    | DIMENSION '(' error ')'
    | POINTER   {aTemp = PTR_ATTR;}
	| PARAMETER {aTemp = PARA_ATTR;}
    ;

sAttr
	: ',' POINTER
	  {
	  	    if(aTemp != ARY_ATTR) yyerror("Same Attribute Decleared.");
	  	  	aTemp = BOTH;
	  }
	| 
	;

expr
    : expr '+' expr
	  {
	  	    if( arithmeticCheck($1, $3) == ERR_TYPE ) 
				yyerror("Arithmetic + TYPE Error.");
			else if( arithmeticCheck($1, $3) == REAL_TYPE )
				$$ = expGenerate(REAL_TYPE);
			else
				$$ = expGenerate(INT_TYPE);

			fprintf(file, "\t\tiadd\n");
	  }
	| expr '-' expr
	  { 
	  	   	Types t = arithmeticCheck($1, $3);
	  	    if(t == ERR_TYPE) 
				yyerror("Arithmetic - TYPE Error.");
			else if(t == REAL_TYPE )
			{
				$$ = expGenerate(REAL_TYPE);
			}
			else
				$$ = expGenerate(INT_TYPE);

			fprintf(file, "\t\tisub\n");
	  }
	| expr '*' expr
	  { 
	  	    if( arithmeticCheck($1, $3) == ERR_TYPE) 
				yyerror("Arithmetic * TYPE Error.");
			else if( arithmeticCheck($1, $3) == REAL_TYPE )
				$$ = expGenerate(REAL_TYPE);
			else
				$$ = expGenerate(INT_TYPE);

			fprintf(file, "\t\timul\n");
	  }
	| expr '/' expr
	  { 
	  	    if( arithmeticCheck($1, $3) == ERR_TYPE) 
				yyerror("Arithmetic // TYPE Error.");
			else if( arithmeticCheck($1, $3) == REAL_TYPE )
				$$ = expGenerate(REAL_TYPE);
			else
				$$ = expGenerate(INT_TYPE);

			fprintf(file, "\t\tidiv\n");
	  }
	| '-' expr %prec UMINUS
	  {
	  	  	if( $2->type != INT_TYPE && $2->type != REAL_TYPE)
				yyerror("unary TYPE not match.");
			if($2->type == INT_TYPE)
				$$ = expGenerate(INT_TYPE);
			else
				$$ = expGenerate(REAL_TYPE);

			fprintf(file, "\t\tineg\n");
	  }
	| expr GT expr
	  {
		    if( expTypeCheck($1, $3) == 0)
				yyerror("Relation expression TYPE Error.");
			$$ = expGenerate(LOGI_TYPE);

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
	| expr GE expr 
	  {
		    if( expTypeCheck($1, $3) == 0)
				yyerror("Relation expression TYPE Error.");
			$$ = expGenerate(LOGI_TYPE);

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
	| expr LT expr 
	  {
	  	   
		    if( expTypeCheck($1, $3) == 0)
				yyerror("Relation expression TYPE Error.");
			$$ = expGenerate(LOGI_TYPE);

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
	| expr LE expr 
	  {
		
		    if( expTypeCheck($1, $3) == 0)
				yyerror("Relation expression TYPE Error.");
			$$ = expGenerate(LOGI_TYPE);

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
	| expr EQ expr 
	  {
		    if( expTypeCheck($1, $3) == 0)
				yyerror("Relation expression TYPE Error.");
			$$ = expGenerate(LOGI_TYPE);

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
	| expr NE expr 
	  {
		    if( expTypeCheck($1, $3) == 0)
				yyerror("Relation expression TYPE Error.");
			$$ = expGenerate(LOGI_TYPE);

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
    | ID
	  {
		  funcName = $1;
	  }

      funcCondition 
	  {
	        symTable *s = searchRecu(currentScope, $1);
			if(s == NULL) yyerror("This id doesn't exist.");
	  	    $$ = expGenerate(s->type);
	  }

	| INTEGERC {$$ = expGenerate(INT_TYPE); fprintf(file, "\t\tsipush %d\n", $1);} 
	| REALC    {$$ = expGenerate(REAL_TYPE); }
	| LOGICALC {$$ = expGenerate(LOGI_TYPE); }
	| STRINGC  {$$ = expGenerate(CHAR_TYPE); ;fprintf(file, "\t\tldc \"%s\"\n", $1);}
	;

funcCondition
    : '(' funcPara ')'
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
    | 
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
	;		

funcPara
    : funcPara ',' opt_val
	| opt_val
    | 
    ;

opt_val
    : INTEGERC
	  {
		  tempType = INT_TYPE;
		  varNum++;

		  fprintf(file, "\t\tsipush %d\n", $1);
	  }
	| REALC    {tempType = REAL_TYPE;}
    | ID        
      {
		  int i;
		  symTable *s = searchRecu(currentScope, $1);
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

		  if(search(currentScope, $1) != NULL)
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
			  fprintf(file, "\t\tgetstatic int %s.%s\n", className, $1);
		  }
      }
	;

optionExpr
	: ',' INTEGERC
	  {
		  inc = $2;
	  }
	| ',' ID { 
	  	    symTable *s = search(currentScope, $2);
			if(s->type != INT_TYPE && s->type != REAL_TYPE) 
				yyerror("optional expr type error.");
	  }
	| 
	  {
		  inc = 1;
	  }
	;

%%

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
