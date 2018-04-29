#define NODE_VAR 0
#define NODE_ARR 1
#define NODE_FUN 2


struct Memberfunclist {

	struct Typetable *Type;
	char *Name;
	struct Argstruct *Arglist;
	int Flabel;
	int Funcposition;
	struct Memberfunclist *Next;

};

struct Classtable {

	struct Fieldlist *Memberfield;
	struct Memberfunclist *Vfuncptr;
	char *Name;
	int Class_index;
	int Fieldcount,Methodcount;
	struct Classtable *Parentptr;
	struct Classtable *Next;
};
struct Classtable *Chead,*Ctail,*Cptr;
int Funcposition=0;

struct Typetable{
	char *Name;
	int Size;
	struct Fieldlist *Field;
	struct Typetable *Next;
};
struct Typetable *Thead,*Ttail;

struct Fieldlist{
	char *Name;
	int Fieldposition;
	char *Typename;
	struct Typetable *Type;
	struct Classtable *Ctype;
	struct Fieldlist *Next;
};
struct Fieldlist *Fhead,*Ftail;

int Fieldposition=0;

struct Gsymbol{
	struct Typetable *Type;
	struct Classtable *Ctype;
	int Node;
	char *Name;
	struct Argstruct *Arglist;
	int Flabel;
	int Binding;
	int Size;
	struct Gsymbol *Next;
};
struct Gsymbol *Ghead,*Gtail;
int Global_binding=4095,Func_count=0,Class_count=-1;
struct Lsymbol{
	struct Typetable *Type;
	char *Name;
	int Binding;
	struct Lsymbol *Next;
};	
struct Lsymbol *Lhead,*Ltail;
int Local_var=0,Arg_count=0;
struct Argstruct{
	struct Typetable *Type;
	char *Name;
	struct Argstruct *Next;
};