%{
	#include<stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "abstree.c"
    #include "codegen.c"
    int yylex();
    void yyerror(char const *s);
    struct Tnode *root,*head;
    int result,a;
    FILE * fp;
    extern FILE *yyin;
    struct Typelist* declarationtype,*Ttemp ;
    struct Gsymbol *Gtemp;
    struct Argstruct *Atemp1,*Atemp2;	
    struct Lsymbol *Ltemp;
	struct Argstruct *Atemp;
	struct Fieldlist *Ftemp;
	struct Tnode* Temp;
%}

%union{
	struct Tnode* nptr;
	struct Typelist *type;
	struct Argstruct *arg;
};

%token <nptr> TYPE ENDTYPE ID NUM DECL ENDDECL START END RETURN ASGN ALLOC FREE READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE INITIALISE PLUS SUB MUL DIV MOD NE EQ GT GE LT LE T F MAIN EQNUL NENUL NUL THIS SELF CLASS ENDCLASS NEW DELETE


%nonassoc GT LT LE EQ NE GE
%left SUB PLUS
%left MUL DIV MOD
%%

Program :  Typedefblock Classdefblock Gdeclblock Fdefblock Mainblock { exit(0);}
	  ;


Typedefblock : TYPE Typedeflist ENDTYPE 
	      | 
	      ;
Typedeflist : Typedeflist Typedef {}
	     | Typedef {}
	     ;
Typedef : ID '{' Fieldlist '}' 
	 ;
Fieldlist : Fieldlist Flds    {}
	   |Flds    
	   ;


Classdefblock : CLASS Classdeflist ENDCLASS  {}
	       |
	       ;
Classdeflist  : Classdeflist Classdef
	       |Classdef
	       ;
Classdef      : Cname'{' Fieldlists MethodDefns '}' 
	       ;

Cname : ID  
        ;

Fieldlists :Fieldlists Flds  {}
	   |
            ;



Flds   : ID ID ';'  {}
				;

MethodDefns  : MethodDefns Fdef
	      |Fdef
	      ;


Gdeclblock : DECL Gdecllist ENDDECL 
	    | {}
	    ;
Gdecllist : Gdecllist Gdecl {}
	   | Gdecl {}
	   ;
Gdecl : Type Varlist ';' {}
		;
Type : ID 	
	;
Varlist :         Varlist ',' ID 
		| Varlist ',' ID '[' NUM ']'
		| Varlist ',' ID '(' Paramlist ')'
		| ID 
		| ID '[' NUM ']' 
		| ID '(' Paramlist ')' 
		;
Paramlist :        Paramlist ',' Param 
		| Param 
		| 
		;
Param : ID ID
	;

Fdefblock   : Fdefblock Fdef{}
	     | 
              ;
              
Signature : ID ID '(' Arglists ')' 
             ;          
Fdef : Signature '{' Ldeclblock START Slist Restmt END '}' 
	   ;
Arglists :  Arglists ',' Arg
	   |Arg
	   |
		   ;
Arg     : ID ID 
		;
Ldeclblock : DECL Ldecllist ENDDECL {}
			| {}
			;
Ldecllist : Ldecllist Ldecl {}
			| Ldecl {}
			;
Ldecl : Type Idlist ';' {}
	  ;
Idlist : Idlist ',' ID 
		| ID
		;

Mainblock : ID MAIN '(' ')' '{' Ldeclblock START Slist Restmt END '}' 
		  ;

Slist : Slist Stmt 
	  |
	  ;
Restmt : RETURN Expr ';' 	
		; 

Stmt: ID ASGN Expr ';' 
	| ID '[' Expr ']' ASGN Expr ';' 				
	| Fields ASGN Expr ';' 
	| ID ASGN NEW '(' ID ')' ';'
	| Fields ASGN NEW '(' ID ')' ';'   {}
	| DELETE '(' Fields ')' ';'        {}
	| ID ASGN NUL ';' 	
	| Fields ASGN NUL ';'
	| ID ASGN INITIALISE '(' ')' ';' 
						
	| Fields ASGN ALLOC '(' ')' ';' 
						
	| ID ASGN ALLOC '(' ')' ';' 
						
	| ID ASGN FREE '(' Fields ')' ';' 
						
	| ID ASGN FREE '(' ID ')' ';' 
						
	| READ '(' ID ')' ';' 
						
	| READ '(' ID '[' Expr ']' ')' ';' 
						
	| READ '(' Fields ')' ';' 
						
	| WRITE '(' Expr ')' ';' 
						
	| IF '(' Expr ')' THEN Slist ENDIF ';' 
						
	| IF '(' Expr ')' THEN Slist ELSE Slist ENDIF ';' 
						
	| WHILE '(' Expr ')' DO Slist ENDWHILE ';' 
						
	;
Fields : ID '.' ID 
         | Fields '.' ID
         |SELF '.' ID
         ;

Expr 	:         Expr PLUS Expr 
		| ID EQNUL 
		| ID NENUL 
		| Fields EQNUL 
		| Fields NENUL 
		| Expr SUB Expr
		| Expr MUL Expr 
		| Expr DIV Expr
		| Expr MOD Expr 
		| Expr NE Expr 
		| Expr EQ Expr
		| Expr LT Expr 
		| Expr LE Expr 
		| Expr GT Expr 
		| Expr GE Expr 
		| '(' Expr ')' 
		| NUM 	
		| ID	
		| ID '[' Expr ']' 	
		| Fields 
		| ID '(' Argalist ')' 	
		| T 
		| F 
		| FieldFunction
		;
Argalist:          Argalist ',' Expr 
		| Expr 
		| 
		;
FieldFunction : Fields '.' ID '('Argalist ')'
                |SELF '.' ID '('Argalist ')'
                |ID '.' ID '('Argalist ')'
                  ;		
%%


void yyerror(char const *s) 
{ 
     printf("yyerror - %s\n",s); exit(0);
    return ;
} 

int main(int argc,char* argv[]) 
{ 
	char* typename=(char*) malloc(sizeof(char)*10);
	strcpy(typename,"int");
	Tinstall(typename,NULL);
	typename=(char*) malloc(sizeof(char)*10);
	strcpy(typename,"bool");
	Tinstall(typename,NULL);
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }  
    yyparse(); 
    return 1; 
}
