%option caseless  
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
"("    {LIST; return *yytext;}
")"    {LIST; return *yytext;}
","    {LIST; return *yytext;}
":"    {LIST; return *yytext;}
"::"   {LIST; return CCOLON;}
";"    {LIST; return *yytext;}
"["    {LIST; return *yytext;}
"]"    {LIST; return *yytext;}
"{"    {LIST; return *yytext;}
"}"    {LIST; return *yytext;}

 /* Define Component Reference */
"%"    {LIST; return PERCENT;}

 /* Define Arithmetic */
"+"    {LIST; return *yytext;}
"-"    {LIST; return *yytext;}
"*"    {LIST; return *yytext;}
"/"    {LIST; return *yytext;}

 /* Define Exponentiation */
"**"   {LIST; return EXP;}

 /* Define Concatentation */
"//"   {LIST; return CONCAT;}

 /* Define Relational */
"<"    {LIST; return LT;}
".LT." {LIST; return LT;}
"<="   {LIST; return LE;}
".LE." {LIST; return LE;}
">="   {LIST; return GE;}
".GE." {LIST; return GE;}
">"    {LIST; return GT;}
".GT." {LIST; return GT;}
"=="   {LIST; return EQ;}
".EQ." {LIST; return EQ;}
"/="   {LIST; return NE;}
".NE." {LIST; return NE;}

 /* Define Logical */
".AND."    {LIST; return AND;}
".OR."     {LIST; return OR;}
".NOT."    {LIST; return NOT;}
".EQV."    {LIST; return EQV;}
".NEQV."   {LIST; return NEQV;}

 /* Define Assignment */
"="    {LIST; return *yytext;}

 /* Define Pointer Assignment */
"=>"   {LIST; return PASSIGNMENT;}

 /* Define Keywords */
"call"        {LIST; return CALL;}
"case"        {LIST; return CASE;}
"close"       {LIST; return CLOSE;}
"continue"    {LIST; return CONTINUE;}
"cycle"       {LIST; return CYCLE;}
"data"        {LIST; return DATA;}
"dimension"   {LIST; return DIMENSION;}
"do"          {LIST; return DO;}
"else"        {LIST; return ELSE;}
"end"         {LIST; return END;}
"exit"        {LIST; return EXIT;}
"function"    {LIST; return FUNCTION;}
"goto"        {LIST; return GOTO;}
"if"          {LIST; return IF;}
"procedure"   {LIST; return PROCEDURE;}
"parameter"   {LIST; return PARAMETER;}
"print"       {LIST; return PRINT;}
"println"     {LIST; return PRINTLN;}
"pointer"     {LIST; return POINTER;}
"program"     {LIST; return PROGRAM;}
"recursive"   {LIST; return RECURSIVE;}
"return"      {LIST; return RETURN;}
"select"      {LIST; return SELECT;}
"stop"        {LIST; return STOP;}
"subroutine"  {LIST; return SUBROUTINE;}
"type"        {LIST; return TYPE;}
"interface"   {LIST; return INTERFACE;}
"then"        {LIST; return THEN;}
"read"        {LIST; return READ;}
"common"      {LIST; return COMMON;}

"integer"     {LIST; return INTEGER;}
"logical"     {LIST; return LOGICAL;}
"real"        {LIST; return REAL;}
"character"   {LIST; return CHARACTER;}

 /* Boolean Constants */
(".TRUE.")|(".FALSE.") {
                LIST; 
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
                LIST;
				*s = 0;
				BEGIN 0;
				yylval.sval = strdup(s);
				return STRINGC;
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
            LIST; 
	   		char* s = (char*)malloc(yyleng*sizeof(char));
			strcpy(s, yytext);
            yylval.sval = strdup(yytext);	 
			return ID;
			}

 /* Integer Constant */
{number}	{
            LIST; 
			yylval.ival = atoi(yytext);
			return INTEGERC;
		   	}

 /* Real Constant */
[+|-]?{digit}*\.{digit}+([eE][+|-]?{digit}+)? {
            LIST; 
	        yylval.dval = atof(yytext);
			return REALC;
			}

\n			{
			LIST;
			printf("%d: %s", linenum++, buf);
			buf[0] = '\0';
            yyless(1);
			}
	

[ \t\r\0]* {LIST;}


.      	    {
			LIST;
			printf("%d:%s\n", linenum+1, buf);
			printf("bad character:'%s'\n",yytext);
			exit(-1);
			}

%%

void yyerror (const char const *s) {
   fprintf (stderr, "line(%d)>token(%s).errMsg:%s\n", linenum, yytext, s);
   exit(EXIT_FAILURE);
}

int yywrap()
{
	return 1;
}
