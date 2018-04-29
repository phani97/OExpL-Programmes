%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "abstree.h"
	union Constant number;
	char *variable,*p,var[30];
%}

number.intval=0;

%%

[0-9]+	{
			union Constant *val=(union Constant*)malloc(sizeof(union Constant));
			val->intval = atoi(yytext);
			yylval.nptr = Treecreate(NULL,NULL,NODE_NUM,NULL,val,NULL,NULL,NULL,NULL);
			/*printf("%d \n",atoi(yytext));*/
			return NUM;
		}
"read"	{ /*printf("READ ");*/return READ;}
"write"	{  /*printf("WRITE ");*/return WRITE;}
"extends" {return EXTENDS;}
"if"	{return IF;}
"else"	{return ELSE;}
"then"	{return THEN;}
"endif"	{return ENDIF;}
"while" {return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}
"begin"	{return START;}
"end"	{return END;}
"decl"	{return DECL;}
"enddecl" {return ENDDECL;}
"main" {return MAIN;}
"return" {return RETURN;}

"true"	{
			yylval.nptr = Treecreate(NULL,NULL,NODE_T,NULL,NULL,NULL,NULL,NULL,NULL);
			return T;
		}
"false"	{
			yylval.nptr = Treecreate(NULL,NULL,NODE_F,NULL,NULL,NULL,NULL,NULL,NULL);
			return F;
		}
"alloc" {return ALLOC;}
"initialize" {return INITIALISE;}
"free" {return FREE;}
"type" {return TYPE;}
"endtype" {return ENDTYPE;}
"null"  {return NUL;}
"class" {return CLASS;}
"endclass" {return ENDCLASS;}
"new"      {return NEW;}
"delete"   {return DELETE;}
"self"     {yylval.nptr = Treecreate(NULL,NULL,NODE_ID_EXPR,variable,NULL,NULL,NULL,NULL,NULL); 
			return SELF;}
[a-zA-Z][a-zA-Z0-9_]*	{//printf("%s",yytext);
			variable = malloc(sizeof(yytext));
			strcpy(variable,yytext);
			yylval.nptr = Treecreate(NULL,NULL,NODE_ID_EXPR,variable,NULL,NULL,NULL,NULL,NULL); 
			/*printf("%s \n",variable);*/
			return ID;
		}
\"(\\.|[^\\\"])*\"   	{
						variable = yytext+1;
						 int i=0;
						 while(*variable != '"')
						 {
						 	var[i]=*variable;
						 	variable++;
						 	i++;
						 }
						 var[i]='\0';
						 p=malloc(sizeof(yytext));
						 strcpy(p,var);
						union Constant *num=(union Constant*)malloc(sizeof(union Constant));
						num->strval=p;
						yylval.nptr = Treecreate(NULL,NULL,NODE_STRVAL,NULL,num,NULL,NULL,NULL,NULL);
						return STRVAL;
					}


"<="	{return LE;}
">="	{return GE;}
"<"		{return LT;}
">"		{return GT;}
"="		{  /*printf("ASGN \n");*/return ASGN;}
"=="	{return EQ;}
"== null" {return EQNUL;}
"!= null" {return NENUL;}
"!="    {return NE;}
"-"		{/*printf("- ");*/return SUB;}
"+"		{/*printf("+ \n");*/return PLUS;}
"*"		{return MUL;}
" "     {}
"/"     {return DIV;}
"%"     {return MOD;}
[ \t] 	{}
"["		{return *yytext;}
"."		{return *yytext;}
"]"		{return *yytext;}
[()] 	{/*printf("PAR ");*/return *yytext;}
[,;]		{/*printf("SC ");*/return *yytext;}
[\n] 	{/*printf("NL ");return NEWLINE;*/}
"{"    {return *yytext;}
"}"     {return *yytext;}
. 		{printf("%c",*yytext);
		yyerror("unknown character\n");
		exit(1);}

%%

int yywrap()
{
	return 1;
}
