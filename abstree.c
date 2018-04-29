struct Tnode* Treecreate(struct Typetable *Type,struct Classtable* Ctype,int Node,char* Name,union Constant *Value,struct Tnode* Arglist,
								struct Tnode* Ptr1,struct Tnode* Ptr2,struct Tnode* Ptr3){
	struct Tnode *Temp = (struct Tnode*) malloc(sizeof(struct Tnode));
	Temp->Type=Type;
	Temp->Ctype=Ctype;
	Temp->Node=Node;
	Temp->Name=Name;
	Temp->Value=Value;
	Temp->Arglist=Arglist;
	Temp->Ptr1=Ptr1;
	Temp->Ptr2=Ptr2;
	Temp->Ptr3=Ptr3;
	Temp->Next=NULL;
	Temp->Gentry=NULL;
	Temp->Lentry=NULL;
	return Temp;
}