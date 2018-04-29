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
    int result,is_classdef;
    FILE * fp;
    extern FILE *yyin;
    struct Typetable* declarationtype,*Ttemp ;
    struct Gsymbol *Gtemp;
    struct Argstruct *Atemp1,*Atemp2;	
    struct Lsymbol *Ltemp;
	struct Argstruct *Atemp;
	struct Fieldlist *Ftemp;
	struct Memberfunclist *Mtemp;
	struct Tnode* Temp;
	struct Classtable *Ctemp,*declarationctype;
%}

%union{
	struct Tnode* nptr;
	struct Typetable *type;
	struct Argstruct *arg;
};

%token <nptr> TYPE ENDTYPE ID NUM DECL ENDDECL START END RETURN ASGN ALLOC FREE READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE INITIALISE PLUS SUB MUL DIV MOD NE EQ GT GE LT LE T F MAIN EQNUL NENUL NUL SELF CLASS ENDCLASS NEW DELETE STRVAL EXTENDS
%type <arg> Paramlist Param Arglists Arg 
%type <type> Type_func 
%type <nptr> Slist Stmt Restmt Expr Field FieldFunction Argalist 

%nonassoc GT LT LE EQ NE GE
%left SUB PLUS
%left MUL DIV MOD
%%

Program :  Typedefblock Classdefblock Gdeclblock Fdefblock Mainblock {exit(0);}
		   ;

Typedefblock    : TYPE Typedeflist ENDTYPE {Initialise_Codegen();Fieldset();is_classdef=1;}
				| 						   {Initialise_Codegen();is_classdef=1;}
				;
Typedeflist : Typedeflist Typedef {}
			| Typedef {}
			;

Typedef : ID '{' Fieldlist '}' {
									Ttemp=Tlookup($1->Name);
									if(Ttemp!=NULL){
										printf("Re-declaration of type\n");
										exit(0);
									}
									Tinstall($1->Name,Fhead);
									Fieldposition=0;
									Fhead=NULL;Ftail=NULL;
								}
		;
Fieldlist	   : Fieldlist Flds {}
				| Flds {}
				;
Flds 			: ID ID ';' 
							{ 
							Ftemp=Fhead;
							while(Ftemp!=NULL){
								if(strcmp($2->Name,Ftemp->Name)==0){
									printf("Re-declaration of field\n");
									exit(0);
								}
								Ftemp=Ftemp->Next;
							}
							Finstall($1->Name,$2->Name);
						} 
				;

Classdefblock : CLASS Classdeflist ENDCLASS  	{ 
													Install_Vfuntable();
													is_classdef=0;
												}
				|	{
						Install_Vfuntable();
						is_classdef=0;
					}
				;
Classdeflist  : Classdeflist Classdef
				|Classdef
				;
Classdef      : Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}' {
														Cptr=NULL;
													}
				;

Cname 		: ID {
					Ttemp = Tlookup($1->Name);
					if(Ttemp!=NULL){
						printf("ALready declared as Type\n");exit(0);
					}
					Ctemp = Clookup($1->Name);
					if(Ctemp!=NULL){
						printf("Already declared as class\n");exit(0);
					}
					Cptr = Cinstall($1->Name,NULL);
					
				}
			| ID EXTENDS ID
				{
					Ttemp = Tlookup($1->Name);
					if(Ttemp!=NULL){
						printf("ALready declared as Type\n");exit(0);
					}
					Ctemp = Clookup($1->Name);
					if(Ctemp!=NULL){
						printf("Already declared as class\n");exit(0);
					}
					Ctemp = Clookup($3->Name);
					if(Ctemp==NULL){
						printf("Extended class is not defined\n");exit(0);
					}
					Cptr = Cinstall($1->Name,$3->Name);
				}
			;
Fieldlists 	: Fieldlists Fld   
			|
			;
Fld : ID ID ';' 
			{ 
				Ftemp=Class_Flookup(Cptr,$2->Name);
				if(Ftemp!=NULL){
					printf("Re-declaration of Field");exit(0);
				}
				Class_Finstall(Cptr,$1->Name,$2->Name);
			} 
	;
MethodDecl : MethodDecl MDecl {}
			| MDecl {}
			;
MDecl : ID ID '(' Paramlist ')' ';' { Ttemp=Tlookup($1->Name);
									if(Ttemp==NULL){
									printf("Undeclared type\n");exit(0);
									}
									Class_Minstall(Cptr,$2->Name,Ttemp,$4);
								 }

MethodDefns  : MethodDefns Fdef  {}
			  |Fdef {}
			   ;


Gdeclblock : DECL Gdecllist ENDDECL  {Initialise_Global();}
			|						 {Initialise_Global();}
			;
Gdecllist : Gdecllist Gdecl {}
		| Gdecl {}
		;
Gdecl : Type Varlist ';' {}
		;
Type : ID 	{
				declarationtype=Tlookup($1->Name);
				declarationctype=Clookup($1->Name);
				if(declarationctype==NULL && declarationtype==NULL){
					printf("Un-declared Type/Class\n");
					exit(0);
				}
			}
	;
Varlist : Varlist ',' ID 	{
								Gtemp=Glookup($3->Name);
								if(Gtemp!=NULL){
									printf("Re-declaration of global variable\n");
									exit(0);
								}
								Ginstall(declarationtype,declarationctype,NODE_VAR,$3->Name,1,NULL);
							}
		| Varlist ',' ID '[' NUM ']' 	{
											Gtemp=Glookup($3->Name);
											if(Gtemp!=NULL){
												printf("Re-declaration of global variable\n");
												exit(0);
											}
											if(declarationctype!=NULL){
												printf("Arrays are not allowed of class type\n");exit(0);
											}
											Ginstall(declarationtype,NULL,NODE_ARR,$3->Name,$5->Value->intval,NULL);
										}

		| Varlist ',' ID '(' Paramlist ')' {
												Gtemp=Glookup($3->Name);
												if(Gtemp!=NULL){
													printf("Re-declaration of global variable\n");
													exit(0);
												}
												if(declarationctype!=NULL){
													printf("Function  arenot allowed of class as return type\n");exit(0);
												}
												Ginstall(declarationtype,NULL,NODE_FUN,$3->Name,-1,$5);
											}
		| ID {
				Gtemp=Glookup($1->Name);
				if(Gtemp!=NULL){
					printf("Re-declaration of global variable\n");
					exit(0);
				}
				Ginstall(declarationtype,declarationctype,NODE_VAR,$1->Name,1,NULL);

			}
		| ID '[' NUM ']' {
							Gtemp=Glookup($1->Name);
							if(Gtemp!=NULL){
								printf("Re-declaration of global variable\n");
								exit(0);
							}
							if(declarationctype!=NULL){
								printf("Arrays arenot allowed of class type\n");exit(0);
							}
							Ginstall(declarationtype,NULL,NODE_ARR,$1->Name,$3->Value->intval,NULL);
						}
		| ID '(' Paramlist ')' {
									Gtemp=Glookup($1->Name);
									if(Gtemp!=NULL){
										printf("Re-declaration of global variable\n");
										exit(0);
									}
									if(declarationctype!=NULL){
										printf("Arrays arenot allowed of class type\n");exit(0);
									}
									Ginstall(declarationtype,NULL,NODE_FUN,$1->Name,-1,$3);
								}
		;

Paramlist : Paramlist ',' Param {
									if($1!=NULL){
										$$=$3;
										$$->Next=$1;
									}
									else {
										$$=$3;
									}
								}
			| Param { $$=$1;}
			| { $$=NULL;}
			;
Param : ID ID  	{
					$$=(struct Argstruct*)malloc(sizeof(struct Argstruct));
					Ttemp=Tlookup($1->Name);
					if(Ttemp==NULL){
						printf("Un-declared Type in Parameters\n");
						exit(0);
					}
					$$->Type=Ttemp;
					$$->Name=$2->Name;
					$$->Next=NULL;
				}
	;
Fdefblock   : Fdefblock Fdef{}
			| 
			;


Fdef : ID ID '(' Arglists ')' '{' Ldeclblock START Slist Restmt END '}' 
						{
							
							Ttemp=Tlookup($1->Name);
							if(Ttemp==NULL){
									printf("Un-defined Type\n");
									exit(0);
								}
							if(is_classdef == 0){
								Gtemp=Glookup($2->Name);
								if(Gtemp==NULL){
									printf("Un-declared function");
									exit(0);
								}
								if(Gtemp->Node!=NODE_FUN){
									printf("Expected Function\n");
									exit(0);
								}
								$2->Gentry=Gtemp;
								Atemp1=$4;
								Atemp2=Gtemp->Arglist;
							
								while(Atemp1!=NULL && Atemp2!=NULL){
									if(Atemp1->Type!=Atemp2->Type){
										printf("Mismatch in type of arguments\n");
										exit(0);
									}
									Atemp1=Atemp1->Next;
									Atemp2=Atemp2->Next;
								}
								if(Atemp1!=NULL || Atemp2!=NULL){
									printf("Mismatch in type of arguments\n");
									exit(0);
								}
								if(Ttemp!=$10->Ptr1->Type || Ttemp!=Gtemp->Type){
									printf("Mismatch in Type of Functions\n");
									exit(0);
								}
								if($9!=NULL){
									Temp=(struct Tnode*)malloc(sizeof(struct Tnode));
									Temp->Node=NODE_VOID;
									Temp->Ptr1=$9;
									Temp->Ptr2=$10;
								}
								else{
									Temp=$10;
								}
								Codegen_func(Gtemp->Flabel,Temp);
							}
							else{

								Mtemp=Mlookup(Cptr,$2->Name);
								if(Mtemp==NULL){
									printf("Un-declared Method\n");
									exit(0);
								}
								Atemp1=$4;
								Atemp2=Mtemp->Arglist;
							
								while(Atemp1!=NULL && Atemp2!=NULL){
									if(Atemp1->Type!=Atemp2->Type){
										printf("Mismatch in type of arguments\n");
										exit(0);
									}
									Atemp1=Atemp1->Next;
									Atemp2=Atemp2->Next;
								}
								if(Atemp1!=NULL || Atemp2!=NULL){
									printf("Mismatch in type of arguments\n");
									exit(0);
								}
								if(Ttemp!=$10->Ptr1->Type || Ttemp!=Mtemp->Type){
									printf("Mismatch in Type of Functions\n");
									exit(0);
								}
								if($9!=NULL){
									Temp=(struct Tnode*)malloc(sizeof(struct Tnode));
									Temp->Node=NODE_VOID;
									Temp->Ptr1=$9;
									Temp->Ptr2=$10;
								}
								else{
									Temp=$10;
								}
								Codegen_func(Mtemp->Flabel,Temp);
							}
							Final_setup();
						}
	   ;
Arglists : Arglists ',' Arg {
								if($1!=NULL){
									$$=$3;
									$$->Next=$1;
								}
								else{
									$$=$3;
								}

							}
		| Arg {$$=$1;}
		| {$$=NULL;}
		;
Arg : ID ID  {

				$$=(struct Argstruct*)malloc(sizeof(struct Argstruct));
				Ttemp=Tlookup($1->Name);
				if(Ttemp==NULL){
					printf("Un-declared Type in Parameters\n");
					exit(0);
				}
				Ltemp=Llookup($2->Name);
				if(Ltemp!=NULL){
					printf("Re-declaration of Variable\n");
					exit(0);
				}
				$$->Type=Ttemp;
				$$->Name=$2->Name;
				$$->Next=NULL;
				Linstall_arg(Ttemp,$2->Name);

			}
	;
Ldeclblock : DECL Ldecllist ENDDECL {}
			| {}
			;
Ldecllist : Ldecllist Ldecl {}
			|  {}
			;
Ldecl : Type_func Idlist ';' {}
	  ;
Type_func : ID 	{
					$$=Tlookup($1->Name);
					declarationtype=$$;
					if($$==NULL){
						printf("Un-declared Type\n");
						exit(0);
					}
				}
			;
Idlist : Idlist ',' ID {
							Ltemp=Llookup($3->Name);
							if(Ltemp!=NULL){
								printf("Re-declaration of Variable\n");
								exit(0);
							}
							Linstall_var(declarationtype,$3->Name);
						}
		| ID 	{
					Ltemp=Llookup($1->Name);
					if(Ltemp!=NULL){
						printf("Re-declaration of Variable\n");
						exit(0);
					}
					Linstall_var(declarationtype,$1->Name);
				}
		;
Mainblock : ID MAIN '(' ')' '{' Ldeclblock START Slist Restmt END '}' 
						{
							Ttemp=Tlookup($1->Name);
							if(Ttemp==NULL){
								printf("Un-defined Type\n");
								exit(0);
							}
							if(strcmp(Ttemp->Name,"int")!=0){
								printf("Needs an int");
								exit(0);
							}
							if(Ttemp!=$9->Ptr1->Type){
								printf("Mismatch in Type of Functions\n");
								exit(0);
							}
							if($8!=NULL){
								Temp=(struct Tnode*)malloc(sizeof(struct Tnode));
								Temp->Node=NODE_VOID;
								Temp->Ptr1=$8;
								Temp->Ptr2=$9;
							}
							else{
								Temp=$9;
							}
							Codegen_func(0,Temp);
							Final_setup();
						}
		  ;
Slist : Slist Stmt {
						if($1==NULL){
							$$=$2;
						}
						else{
							$$=(struct Tnode*)malloc(sizeof(struct Tnode));
							$$->Node=NODE_VOID;
							$$->Ptr1=$1;
							$$->Ptr2=$2;
						}
					}
	  | { $$=NULL; }
	  ;
Restmt : RETURN Expr ';' 	{
								$$=(struct Tnode*)malloc(sizeof(struct Tnode));
								$$->Node=NODE_RET;
								$$->Ptr1=$2;
							}
		; 

Stmt: ID ASGN Expr ';' 	{
							Ltemp=Llookup($1->Name);
							if(Ltemp!=NULL){
								$1->Type=Ltemp->Type;
								$1->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different %s\n",$1->Name);
								exit(0);
							}
							else{
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$1->Gentry=Gtemp;
								$1->Type=Gtemp->Type;
								$1->Ctype=Gtemp->Ctype;
							}
							if($1->Type!=NULL){
								if($1->Type!=$3->Type){
									printf("Conflicting types in asgn\n");exit(0);
								}
								$$=Treecreate(NULL,NULL,NODE_ID_ASGN,NULL,NULL,NULL,$1,NULL,$3);
							}
							else{
								type_comp($1->Ctype,$3->Ctype);
								$$=Treecreate(NULL,NULL,NODE_ID_ASGN_CLASS,NULL,NULL,NULL,$1,NULL,$3);
							}
						}
	| ID '[' Expr ']' ASGN Expr ';' 
					{
						if (is_classdef == 1){
							printf("Arrays are not permitted in classes\n");
							exit(0);
						}
						Gtemp=Glookup($1->Name);
						if(Gtemp==NULL){
							printf("Un-declared Variable\n");
							exit(0);
						}
						if(Gtemp->Node!=NODE_ARR){
							printf("Expected Arr\n");exit(0);
						}
						if($3->Type!=Tlookup("int")){
							printf("index must be int\n");exit(0);
						}
						$1->Type=Gtemp->Type;
						$1->Gentry=Gtemp;
						if($1->Type!=$6->Type){
							printf("conflicting types in asgn\n");exit(0);
						}
						$$=Treecreate(NULL,NULL,NODE_ARR_ASGN,NULL,NULL,NULL,$1,$3,$6);
					}				
	| Field ASGN Expr ';' 	{
								if($1->Type!=NULL){
									if($1->Type!=$3->Type){
										printf("Conflicting types in asgn\n");exit(0);
									}
									$$=Treecreate(NULL,NULL,NODE_FIELD_ASGN,NULL,NULL,NULL,$1,NULL,$3);
								}
								else{
									if($1->Ctype!=$3->Ctype){
										printf("Conflicting types by class in asgn\n");exit(0);
									}
									$$=Treecreate(NULL,NULL,NODE_FIELD_ASGN_CLASS,NULL,NULL,NULL,$1,NULL,$3);
								}
							}
	| ID ASGN NEW '(' ID ')' ';'	{
										if(is_classdef == 1){
											printf("Accessing of Mem fields is wrong\n");
											exit(0);
										}
										Gtemp = Glookup($1->Name);
										if(Gtemp == NULL){
											printf("Un-declared Variable\n");
											exit(0);
										}
										$1->Gentry=Gtemp;
										$1->Ctype=Gtemp->Ctype;
										if($1->Ctype == NULL){
											printf("Variable is not of class type %s\n",$1->Type->Name);
											exit(0);
										}
										Ctemp = Clookup($5->Name);
										if(Ctemp == NULL){
											printf("CLass Un-declared\n");
											exit(0);
										}
										type_comp($1->Ctype,Ctemp);
										$5->Ctype=Ctemp;
										$$=Treecreate(NULL,NULL,NODE_OBJID_NEW,NULL,NULL,NULL,$1,$5,NULL);
									}
	| Field ASGN NEW '(' ID ')' ';'   	{
											Ctemp = Clookup($5->Name);
											if(Ctemp == NULL){
												printf("Class Un-declared\n");
												exit(0);
											}
											if($1->Ctype == NULL){
												printf("Field is not of class type\n");
												exit(0);
											}
											type_comp($1->Ctype,Ctemp);
											$5->Ctype=Ctemp;
											$$=Treecreate(NULL,NULL,NODE_OBJFIELD_NEW,NULL,NULL,NULL,$1,$5,NULL);
										}
	| DELETE '(' Field ')' ';'     	{
										if($3->Ctype == NULL){
											printf("Field is not of class type\n");
											exit(0);
										}
										$$=Treecreate(NULL,NULL,NODE_OBJFIELD_DELETE,NULL,NULL,NULL,$3,NULL,NULL);
									}
	| DELETE '(' ID ')' ';'        	{
										if(is_classdef == 1){
											printf("Accessing of Mem fields is wrong\n");
											exit(0);
										}
										Gtemp = Glookup($3->Name);
										if(Gtemp == NULL){
											printf("Un-declared Variable\n");
											exit(0);
										}
										$3->Gentry=Gtemp;
										$3->Ctype=Gtemp->Ctype;
										if($3->Ctype == NULL){
											printf("Variable is not of class type\n");
											exit(0);
										}
									$$=Treecreate(NULL,NULL,NODE_OBJID_DELETE,NULL,NULL,NULL,$3,NULL,NULL);
									}
	| ID ASGN NUL ';' 	{
							Ltemp=Llookup($1->Name);
							if(Ltemp!=NULL){
								$1->Type=Ltemp->Type;
								$1->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable\n");
								exit(0);
							}
							else{
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$1->Gentry=Gtemp;
								$1->Type=Gtemp->Type;
								$1->Ctype=Gtemp->Ctype;
							}
							if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool") || $1->Type==Tlookup("str")){
								printf("can't make it NULL\n");exit(0);
							}
							if($1->Type != NULL){
								$$=Treecreate(NULL,NULL,NODE_ID_NULL,NULL,NULL,NULL,$1,NULL,NULL);
							}
							else{
								$$=Treecreate(NULL,NULL,NODE_ID_NULL_CLASS,NULL,NULL,NULL,$1,NULL,NULL);
							}
						}
	| Field ASGN NUL ';'{
							if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool") || $1->Type==Tlookup("str")){
								printf("can't make it NULL\n");exit(0);
							}
							if($1->Type != NULL){
								$$=Treecreate(NULL,NULL,NODE_FIELD_NULL,NULL,NULL,NULL,$1,NULL,NULL);
							}
							else{
								$$=Treecreate(NULL,NULL,NODE_FIELD_NULL_CLASS,NULL,NULL,NULL,$1,NULL,NULL);
							}
						}
	| ID ASGN INITIALISE '(' ')' ';' 
						{
							Ltemp=Llookup($1->Name);
							if(Ltemp!=NULL){
								$1->Type=Ltemp->Type;
								$1->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different2\n");
								exit(0);
							}
							else{
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$1->Gentry=Gtemp;
								$1->Type=Gtemp->Type;
							}
							if($1->Type!=Tlookup("int")){
								printf("Return type of initialise is INT\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_INITIALIZE,NULL,NULL,NULL,$1,NULL,NULL);
						}
	| Field ASGN ALLOC '(' ')' ';' 
						{
							if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool") || $1->Type==NULL || $1->Type==Tlookup("str")){
								printf("can't give memory for int and bool or giving memory for classes is diff\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_FIELD_ALLOC,NULL,NULL,NULL,$1,NULL,NULL);
						}
	| ID ASGN ALLOC '(' ')' ';' 
						{
							Ltemp=Llookup($1->Name);
							if(Ltemp!=NULL){
								$1->Type=Ltemp->Type;
								$1->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable\n");
								exit(0);
							}
							else{
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$1->Gentry=Gtemp;
								$1->Type=Gtemp->Type;
							}
							if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool") || $1->Type==NULL || $1->Type==Tlookup("str")){
								printf("can't give memory for int and bool\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_ID_ALLOC,NULL,NULL,NULL,$1,NULL,NULL);
						}
	| ID ASGN FREE '(' Field ')' ';' 
						{
							Ltemp=Llookup($1->Name);
							if(Ltemp!=NULL){
								$1->Type=Ltemp->Type;
								$1->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different3\n");
								exit(0);
							}
							else{
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$1->Gentry=Gtemp;
								$1->Type=Gtemp->Type;
							}
							if($1->Type!=Tlookup("int")){
								printf("Return type of free is INT\n");exit(0);
							}
							if($5->Type==Tlookup("int") || $5->Type==Tlookup("bool") || $5->Type==NULL || $5->Type==Tlookup("str")){
								printf("WE can't free variables of int and bool types or making variables of class type is diff\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_FIELD_FREE,NULL,NULL,NULL,$1,$5,NULL);
						}
	| ID ASGN FREE '(' ID ')' ';' 
						{
							Ltemp=Llookup($1->Name);
							if(Ltemp!=NULL){
								$1->Type=Ltemp->Type;
								$1->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different4\n");
								exit(0);
							}
							else{
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$1->Gentry=Gtemp;
								$1->Type=Gtemp->Type;
							}
							if($1->Type!=Tlookup("int")){
								printf("Return type of free is INT\n");exit(0);
							}
							Ltemp=Llookup($5->Name);
							if(Ltemp!=NULL){
								$5->Type=Ltemp->Type;
								$5->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different5\n");
								exit(0);
							}
							else{
								Gtemp=Glookup($5->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$5->Gentry=Gtemp;
								$5->Type=Gtemp->Type;
							}
							if($5->Type==Tlookup("int") || $5->Type==Tlookup("bool") || $5->Type==NULL || $5->Type==Tlookup("str")){
								printf("WE can't free variables of int and bool types\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_ID_FREE,NULL,NULL,NULL,$1,$5,NULL);
						}
	| READ '(' ID ')' ';' 
						{
							Ltemp=Llookup($3->Name);
							if(Ltemp!=NULL){
								$3->Type=Ltemp->Type;
								$3->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different6\n");
								exit(0);
							}
							else{
								Gtemp=Glookup($3->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								$3->Gentry=Gtemp;
								$3->Type=Gtemp->Type;
							}
							if($3->Type!=Tlookup("int")&&$3->Type!=Tlookup("str")){
								printf("Reading only int type variable\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_ID_READ,NULL,NULL,NULL,$3,NULL,NULL);
						}
	| READ '(' ID '[' Expr ']' ')' ';' 
						{
							if (is_classdef == 1){
								printf("Arrays are not included in classes\n");
								exit(0);
							}
							Gtemp=Glookup($3->Name);
							if(Gtemp==NULL){
								printf("Un-declared Variable\n");
								exit(0);
							}
							if(Gtemp->Node!=NODE_ARR){
								printf("Expected Array\n");
								exit(0);
							}
							$3->Gentry=Gtemp;
							$3->Type=Gtemp->Type;
							if($5->Type!=Tlookup("int")){
								printf("Index must be integer\n");exit(0);
							}
							if($3->Type!=Tlookup("int")){
								printf("Reading only int type var\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_ARR_READ,NULL,NULL,NULL,$3,$5,NULL);
						}
	| READ '(' Field ')' ';' 
						{
							if($3->Type!=Tlookup("int")&&$3->Type!=Tlookup("str")){
								printf("Reading only int type var\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_FIELD_READ,NULL,NULL,NULL,$3,NULL,NULL);
						}
	| WRITE '(' Expr ')' ';' 
						{
							if($3->Type!=Tlookup("int")&&$3->Type!=Tlookup("str")){
								printf("Printing only int type var\n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_WRITE,NULL,NULL,NULL,$3,NULL,NULL);
						}
	| IF '(' Expr ')' THEN Slist ENDIF ';' 
						{
							if($3->Type!=Tlookup("bool")){
								printf("Conditions only bool type \n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_IF,NULL,NULL,NULL,$3,$6,NULL);
						}
	| IF '(' Expr ')' THEN Slist ELSE Slist ENDIF ';' 
						{
							if($3->Type!=Tlookup("bool")){
								printf("Conditions only bool type \n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_IF_ELSE,NULL,NULL,NULL,$3,$6,$8);
						}
	| WHILE '(' Expr ')' DO Slist ENDWHILE ';' 
						{
							if($3->Type!=Tlookup("bool")){
								printf("Conditions only bool type \n");exit(0);
							}
							$$=Treecreate(NULL,NULL,NODE_WHILE,NULL,NULL,NULL,$3,$6,NULL);
						}
	;

Field 	: ID '.' ID
					{
						Ltemp=Llookup($1->Name);
						if(Ltemp!=NULL){
							$1->Lentry=Ltemp;
							$1->Type=Ltemp->Type;
							Ftemp=Flookup(Ltemp->Type,$3->Name);
						}
						else if (is_classdef == 1){
							printf("Un-declared Variable or Accessing of mem fields is different7\n");
							exit(0);
						}
						else{
							Gtemp=Glookup($1->Name);
							if(Gtemp==NULL){
								printf("Variable not declared\n");
								exit(0);
							}
							if(Gtemp->Type==NULL){
								printf("Mem fields of class are of private type\n");exit(0);
							}
							if(Gtemp->Node!=NODE_VAR){
								printf("Expected Var,Found something\n");
								exit(0);
							}
							$1->Gentry=Gtemp;
							$1->Type=Gtemp->Type;
							Ftemp=Flookup(Gtemp->Type,$3->Name);
							}
						if(Ftemp==NULL){
							printf("It is not a field in that type\n");
							exit(0);
						}
						$3->Type=Ftemp->Type;
						$$=Treecreate($3->Type,NULL,NODE_FIELD_ID,NULL,NULL,NULL,$1,$3,NULL);
					}
		| Field '.' ID 	{
							if($1->Type==NULL){
								printf("Member fields of class are of private type\n");exit(0);
							}
							Ftemp= Flookup($1->Type,$3->Name);
							if(Ftemp == NULL){
								printf("It is not a field in that type/ class");exit(0);
							}
							$3->Type=Ftemp->Type;
							$$=Treecreate($3->Type,NULL,NODE_FIELD,NULL,NULL,NULL,$1,$3,NULL);
						}
		| SELF '.' ID 	{	
							Ftemp= Class_Flookup(Cptr,$3->Name);
							if(Ftemp == NULL){
								printf("It is not a field in that type/class");
								exit(0);
							}
							$3->Type=Ftemp->Type;
							$3->Ctype=Ftemp->Ctype;
							$1->Ctype=Cptr;
							$$=Treecreate($3->Type,$3->Ctype,NODE_SELF_ID,NULL,NULL,NULL,$1,$3,NULL);
						}
		;

FieldFunction 	: Field '.' ID '(' Argalist ')' 
							{
								if($1->Ctype == NULL){
									printf("Calling reference is not an obj\n");exit(0);
								}
								Mtemp = Mlookup($1->Ctype,$3->Name);
								if(Mtemp == NULL){
									printf("Method doesn't exist\n");exit(0);
								}
								Temp=$5;
								Atemp=Mtemp->Arglist;
								while(Temp!=NULL && Atemp!=NULL){
									
									if(Temp->Type!=Atemp->Type){
										printf("Confilcts in arguments\n");
										exit(0);
									}
									Temp=Temp->Next;
									Atemp=Atemp->Next;
								}
								if(Temp!=NULL || Atemp!=NULL){
									printf("Confilcts in arguments\n");
									exit(0);
								}
								$$=Treecreate(Mtemp->Type,NULL,NODE_FIELD_METHOD,NULL,NULL,$5,$3,NULL,NULL);
								$$->Obj = $1;
							}
				| SELF '.' ID '(' Argalist ')'
							{
								Mtemp=Mlookup(Cptr,$3->Name);
								if(Mtemp == NULL){
									printf("Method doesn't exist\n");exit(0);
								}
								Temp=$5;
								Atemp=Mtemp->Arglist;
								while(Temp!=NULL && Atemp!=NULL){
									
									if(Temp->Type!=Atemp->Type){
										printf("Confilcts in arguments\n");
										exit(0);
									}
									Temp=Temp->Next;
									Atemp=Atemp->Next;
								}
								if(Temp!=NULL || Atemp!=NULL){
									printf("Confilcts in arguments\n");
									exit(0);
								}
								$1->Ctype=Cptr;
								$$=Treecreate(Mtemp->Type,NULL,NODE_SELF_METHOD,NULL,NULL,$5,$3,NULL,NULL);
								$$->Obj = $1;
							}
				| ID '.' ID '(' Argalist ')'
							{
								if(is_classdef==1){
									printf("Accessing of mem field is wrong\n");exit(0);
								}
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Ctype==NULL){
									printf("Variable is not of class type\n");
									exit(0);
								}
								$1->Gentry=Gtemp;
								$1->Ctype=Gtemp->Ctype;
								Mtemp=Mlookup(Gtemp->Ctype,$3->Name);
								if(Mtemp == NULL){
									printf("Method doesn't exist\n");exit(0);
								}
								Temp=$5;
								Atemp=Mtemp->Arglist;
								while(Temp!=NULL && Atemp!=NULL){
									
									if(Temp->Type!=Atemp->Type){
										printf("Confilcts in arguments\n");
										exit(0);
									}
									Temp=Temp->Next;
									Atemp=Atemp->Next;
								}
								if(Temp!=NULL || Atemp!=NULL){
									printf("Confilcts in arguments\n");
									exit(0);
								}
								$$=Treecreate(Mtemp->Type,NULL,NODE_ID_METHOD,NULL,NULL,$5,$3,NULL,NULL);
								$$->Obj = $1;
							}
				;

Expr 	: Expr PLUS Expr {
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Ttemp,NULL,NODE_PLUS,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in PLUS\n");exit(0);
							}
						}
		| ID EQNUL {
						Ltemp=Llookup($1->Name);
						if(Ltemp!=NULL){
							$1->Lentry=Ltemp;
							$1->Type=Ltemp->Type;
						}
						else if (is_classdef == 1){
							printf("Un-declared Variable or Accessing of mem fields is different8\n");
							exit(0);
						}
						else{
							Gtemp=Glookup($1->Name);
							if(Gtemp==NULL){
								printf("Not declared variable\n");
								exit(0);
							}
							if(Gtemp->Node!=NODE_VAR){
								printf("Expected Var,Found something\n");
								exit(0);
							}
							$1->Gentry=Gtemp;
							$1->Type=Gtemp->Type;
							$1->Ctype=Gtemp->Ctype;
						}
						if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool")||
						$1->Type==Tlookup("str")){
							printf("Can't compare null\n");
							exit(0);
						}
						$$=Treecreate(Tlookup("bool"),NULL,NODE_ID_EQ,NULL,NULL,NULL,$1,NULL,NULL);
					}
		| ID NENUL 	{
						Ltemp=Llookup($1->Name);
						if(Ltemp!=NULL){
							$1->Lentry=Ltemp;
							$1->Type=Ltemp->Type;
						}
						else if (is_classdef == 1){
							printf("Un-declared Variable or Accessing of mem fields is different9\n");
							exit(0);
						}
						else{
							Gtemp=Glookup($1->Name);
							if(Gtemp==NULL){
								printf("Not declared variable\n");
								exit(0);
							}
							if(Gtemp->Node!=NODE_VAR){
								printf("Expected Var,Found something\n");
								exit(0);
							}
							$1->Gentry=Gtemp;
							$1->Type=Gtemp->Type;
							$1->Ctype=Gtemp->Ctype;
						}
						if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool")|| 
						$1->Type==Tlookup("str")){
							printf("Can't Compare null\n");
							exit(0);
						}
						$$=Treecreate(Tlookup("bool"),NULL,NODE_ID_NE,NULL,NULL,NULL,$1,NULL,NULL);
					}
		| Field EQNUL 	{
							if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool")|| 
							$1->Type==Tlookup("str")){
								printf("Can't make null\n");
								exit(0);
							}
							$$=Treecreate(Tlookup("bool"),NULL,NODE_FIELD_EQ,NULL,NULL,NULL,$1,NULL,NULL);
						}
		| Field NENUL 	{
							if($1->Type==Tlookup("int") || $1->Type==Tlookup("bool")|| 
							$1->Type==Tlookup("str")){
								printf("Can't make null\n");
								exit(0);
							}
							$$=Treecreate(Tlookup("bool"),NULL,NODE_FIELD_NE,NULL,NULL,NULL,$1,NULL,NULL);
						}
		| Expr SUB Expr	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Ttemp,NULL,NODE_SUB,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in SUB\n");exit(0);
							}
						}
		| Expr MUL Expr {
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Ttemp,NULL,NODE_MUL,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in MUL\n");exit(0);
							}
						}
		| Expr DIV Expr	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Ttemp,NULL,NODE_DIV,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in DIV\n");exit(0);
							}
						}
		| Expr MOD Expr {
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Ttemp,NULL,NODE_MOD,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in MOD\n");exit(0);
							}
						}
		| Expr NE Expr 	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Tlookup("bool"),NULL,NODE_NE,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in NE\n");exit(0);
							}
						}
		| Expr EQ Expr	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Tlookup("bool"),NULL,NODE_EQ,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in EQ\n");exit(0);
							}
						}
		| Expr LT Expr 	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Tlookup("bool"),NULL,NODE_LT,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in LT\n");exit(0);
							}
						}
		| Expr LE Expr 	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Tlookup("bool"),NULL,NODE_LE,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in LE\n");exit(0);
							}
						}
		| Expr GT Expr 	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Tlookup("bool"),NULL,NODE_GT,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in GT\n");exit(0);
							}
						}
		| Expr GE Expr 	{
							Ttemp=Tlookup("int");
							if($1->Type==Ttemp && $3->Type==Ttemp){
								$$=Treecreate(Tlookup("bool"),NULL,NODE_GE,NULL,NULL,NULL,$1,$3,NULL);
							}
							else {
								printf("Conflicting types in GE\n");exit(0);
							}
						}
		| '(' Expr ')' {$$=$2;}
		| NUM 	{ 
					$$=$1;
					$$->Type=Tlookup("int");
				}
		| ID	{
					Ltemp=Llookup($1->Name);
					if(Ltemp!=NULL){
						$1->Type=Ltemp->Type;
						$1->Lentry=Ltemp;
						$$=$1;
					}
					else if(is_classdef == 1){
						printf("Un-declared Variable or Accessing of mem fields is different10\n");
						exit(0);
					}
					else{
						Gtemp=Glookup($1->Name);
						if(Gtemp==NULL){
							printf("Not Declared %s\n",$1->Name);
							exit(0);
						}
						if(Gtemp->Node!=NODE_VAR){
							printf("Expected Var,Found something\n");exit(0);
						}
						$1->Type=Gtemp->Type;
						$1->Ctype=Gtemp->Ctype;
						$1->Gentry=Gtemp;
						$$=$1;
					}
			}	
		| ID '[' Expr ']' 	{
								if(is_classdef == 1){
									printf(" Arrays are not supported in classes\n");
									exit(0);
								}
								Gtemp=Glookup($1->Name);
								if(Gtemp==NULL){
									printf("Not Declared \n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_ARR){
									printf("Expected Arr,Found something\n");exit(0);
								}
								if(Gtemp->Ctype!=NULL){
									printf("Arrays of class type won't exist\n");exit(0);
								}
								$1->Type=Gtemp->Type;
								$1->Gentry=Gtemp;
								if($3->Type!=Tlookup("int")){
									printf("Index must be integer\n");
									exit(0);
								}
								$$=Treecreate($1->Type,NULL,NODE_ARR_EXPR,NULL,NULL,NULL,$1,$3,NULL);
							}
		| Field {$$=Treecreate($1->Type,$1->Ctype,NODE_FIELD_EXPR,NULL,NULL,NULL,$1,NULL,NULL);}
		| ID '(' Argalist ')' 	{
									if(is_classdef == 1){
										printf("Method calling is wrong in classes\n");
										exit(0);
									}
									Gtemp=Glookup($1->Name);
									if(Gtemp==NULL){
										printf("Not Declared %s\n",$1->Name);
										exit(0);
									}
									if(Gtemp->Node!=NODE_FUN){
										printf("Expected FUNC,Found something\n");exit(0);
									}
									Temp=$3;
									Atemp=Gtemp->Arglist;
									while(Temp!=NULL && Atemp!=NULL){
										
										if(Temp->Type!=Atemp->Type){
											printf("Confilcts in arguments\n");
											exit(0);
										}
										Temp=Temp->Next;
										Atemp=Atemp->Next;
									}
									if(Temp!=NULL || Atemp!=NULL){
										printf("Conflicts in arguments\n");
										exit(0);
									}
									$1->Gentry=Gtemp;
									$1->Type=Gtemp->Type;
									$$=Treecreate(Gtemp->Type,NULL,NODE_FUNC,NULL,NULL,$3,$1,NULL,NULL);

								}
		| T {$$=$1;}
		| F {$$=$1;}
		| FieldFunction			 {$$=$1;}
		| STRVAL				 {$$=$1;$$->Type=Tlookup("str");}
		;
Argalist: Argalist ',' Expr {
								if($1!=NULL){
									$$=$3;
									$$->Next=$1;
								}
								else{
									$$=$3;
								}
							}
		| Expr {$$=$1;}
		| {$$=NULL;}
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
	typename=(char*) malloc(sizeof(char)*10);
	strcpy(typename,"str");
	Tinstall(typename,NULL);
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    } 
    is_classdef=1; 
    yyparse(); 
    return 1; 
}
