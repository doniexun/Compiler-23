%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
	
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];

/* Used to State<STRING>
   This buffer is contain string that is copy from yytext.
   Pointer s is point to buffer "strBuf". */
char strBuf[MAX_LINE_LENG];
char *s;

%}
comment  [C |* ]
digit    [0-9]
number   {digit}+
letter   [a-zA-Z]
id       {letter}({letter}|{digit})*

%x STRING
%x COMMENT1
%x COMMENT2

%%
 /* Define Delimiters */
"("    {return *yytext;}
")"    {return *yytext;}
","    {return *yytext;}
":"    {return *yytext;}
"::"   {return CCOLON;}
";"    {return *yytext;}
"["    {return *yytext;}
"]"    {return *yytext;}
"{"    {return *yytext;}
"}"    {return *yytext;}

 /* Define Component Reference */
"%"    {return PERCENT;}

 /* Define Arithmetic */
"+"    {return *yytext;}
"-"    {return *yytext;}
"*"    {return *yytext;}
"/"    {return *yytext;}

 /* Define Exponentiation */
"**"   {return EXP;}

 /* Define Concatentation */
"//"   {return CONCAT;}

 /* Define Relational */
"<"    {return LT;}
".LT." {return LT;}
"<="   {return LE;}
".LE." {return LE;}
">="   {return GE;}
".GE." {return GE;}
">"    {return GT;}
".GT." {return GT;}
"=="   {return EQ;}
".EQ." {return EQ;}
"/="   {return NE;}
".NE." {return NE;}

 /* Define Logical */
".AND."    {return AND;}
".OR."     {return OR;}
".NOT."    {return NOT;}
".EQV."    {return EQV;}
".NEQV."   {return NEQV;}

 /* Define Assignment */
"="    {return *yytext;}

 /* Define Pointer Assignment */
"=>"   {return PASSIGNMENT;}

 /* Define Keywords */
"call"        {return CALL;}
"case"        {return CASE;}
"close"       {return CLOSE;}
"continue"    {return CONTINUE;}
"cycle"       {return CYCLE;}
"data"        {return DATA;}
"dimension"   {return DIMENSION;}
"do"          {return DO;}
"else"        {return ELSE;}
"end"         {return END;}
"exit"        {return EXIT;}
"function"    {return FUNCTION;}
"goto"        {return GOTO;}
"if"          {return IF;}
"procedure"   {return PROCEDURE;}
"parameter"   {return PARAMETER;}
"print"       {return PRINT;}
"println"     {return PRINTLN;}
"pointer"     {return POINTER;}
"program"     {return PROGRAM;}
"recursive"   {return RECURSIVE;}
"return"      {return RETURN;}
"select"      {return SELECT;}
"stop"        {return STOP;}
"subroutine"  {return SUBROUTINE;}
"type"        {return TYPE;}
"interface"   {return INTERFACE;}

"integer"     {return INTEGER;}
"logical"     {return LOGICAL;}
"real"        {return REAL;}
"character"   {return CHARACTER;}

 /* Boolean Constants */
(".TRUE.")|(".FALSE.") {
				if(!strcmp(".TRUE.", yytext))
				 yylval.bval = 1;
				else
				 yylval.bval = 0;
					
				return LOGICALC;	
				}

 /* State<STRING> is for String Constants */
\"           	{
				LIST;
				BEGIN(STRING);
				s = strBuf;
				}

<STRING>\"      {
				*s = 0;
				BEGIN 0;
				yylval.sval = strdup(yytext);
				return STRING;
				}

<STRING>\"{2,2} {
				LIST;
				*s++ = '"';
				}

<STRING>. 		{
				LIST;
				*s++ = *yytext;
				}

 /* State<COMMENT1> (for C * !) */
^(("C ")|("* ")) {LIST;	BEGIN(COMMENT1);}
"! "             {LIST; BEGIN(COMMENT1);}
<COMMENT1>\n {
			yyless(yyleng-1);
			BEGIN 0;
			}
<COMMENT1>. {LIST;}

 /* State<COMMENT2> (for star symbol comment) */
"/*" 		{
			BEGIN(COMMENT2);
			}
<COMMENT2>\n {
			printf("%d: %s\n", linenum++, buf);
			buf[0] = 0;
			}
<COMMENT2>"*/" {
			LIST;
			BEGIN 0;
			}
<COMMENT2>. {LIST;}
	


 /* Identifiers */
{id}+  		{
	   		char* s = (char*)malloc(yyleng*sizeof(char));
			strcpy(s, yytext);
			tokenString("Identifier", yytext);
            yylval.sval = strdup(yytext);	 
			return ID;
			}

 /* Integer Constant */
{number}	{
			yylval.ival = atoi(yytext);
			return INTEGERC;
		   	}

 /* Real Constant */
[+|-]?{digit}*\.{digit}+([eE][+|-]?{digit}+)? {
	        yylval.dval = atof(yytext);
			return REALC;
			}

\n			{
			LIST;
			printf("%d: %s", linenum++, buf);
			buf[0] = '\0';
			}
	

[ \t\r\0]* {LIST;}


.      	    {
			LIST;
			printf("%d:%s\n", linenum+1, buf);
			printf("bad character:'%s'\n",yytext);
			exit(-1);
			}

%%

int yywrap()
{
	return 1;
}
