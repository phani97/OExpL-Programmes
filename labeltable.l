%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "labeltable.h"
	#include "labeltable.c"
	#include<string.h>
	int lineaddress=2040;
	FILE *fp;
	char *p;
	int gval=0;
%}

%%

"\n" {if(gval==0){lineaddress=lineaddress+2;}if(gval==1){fprintf(fp,"\n");}}

[LF][0-9]+"\n" {if(gval==0){lineaddress=lineaddress+2;}if(gval==1){yytext[yyleng-1]='\0';fprintf(fp,"%d\n",replacelabel(yytext));}}

[LF][0-9]+":\n" {if(gval==0){insertlabel(yytext,lineaddress);}}

. {if(gval==1)fprintf(fp,"%s",yytext);}

%%

int yywrap()
{
  if(gval==0)
  {
    yyin=fopen("assemblycode.xsm","r");
  
    fp=fopen("assemblycodenew.xsm","w");
    gval=1;
    return 0;
  }
  else
  {
  	return 1;
  }
}

int main(int argc,char *argv[])
{
	yyin=fopen("assemblycode.xsm","r");
	//p=argv[1];
	yylex();
}




