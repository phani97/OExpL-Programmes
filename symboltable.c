void Tinstall(char *Name,struct Fieldlist *Field){
	struct Typetable *temp = (struct Typetable*) malloc(sizeof(struct Typetable));
	temp->Name=Name;
	temp->Field=Field;
	if(Field==NULL)
		 temp->Size=0;
	else {
		temp->Size=0;
		while(Field!=NULL){
			temp->Size++;
			Field=Field->Next;
		}
	}
	temp->Next=NULL;
	if(Thead==NULL){
		Thead=temp;
		Ttail=temp;
	}
	else {
		Ttail->Next=temp;
		Ttail=temp;
	}
}
void type_comp(struct Classtable *ptr1,struct Classtable *ptr2){
	while(ptr2!=NULL){
		if(ptr1==ptr2) return;
		ptr2=ptr2->Parentptr;
	}
	printf("Class types are not compatible to each other\n");
	exit(0);
}
struct Classtable* Clookup(char *Name){
	struct Classtable* temp = Chead;
	while(temp!=NULL){
		if(strcmp(temp->Name,Name)==0){
			return temp;
		}
		temp=temp->Next;
	}
	return NULL;
}
struct Typetable* Tlookup(char *Name){
	struct Typetable* temp = Thead;
	while(temp!=NULL){
		if(strcmp(temp->Name,Name)==0){
			return temp;
		}
		temp=temp->Next;
	}
	return NULL;
}
void Finstall(char *Typename,char* Name){
	struct Fieldlist *temp= (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
	temp->Typename=Typename;
	temp->Name=Name;
	temp->Fieldposition=Fieldposition;
	Fieldposition++;
	temp->Next=NULL;
	if(Fhead==NULL){
		Fhead=temp;
		Ftail=temp;
	}
	else {
		Ftail->Next=temp;
		Ftail=temp;
	}
	if(Fieldposition>8)
	{
		printf("Max field size is 8\n");
		exit(0);
	}
}
void Class_Finstall(struct Classtable *Cptr,char *Typename,char *Name){
	struct Fieldlist *temp= (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
	temp->Name=Name;
	temp->Fieldposition=Cptr->Fieldcount;
	Cptr->Fieldcount++;
	if(Cptr->Fieldcount>8){
		printf("Max limit of fields reached\n");
		exit(0);
	}
	temp->Type=Tlookup(Typename);
	temp->Ctype=Clookup(Typename);
	if(temp->Type==NULL && temp->Ctype==NULL){
		printf("Type/Class of field doesn't exist\n");exit(0);
	}
	temp->Next=Cptr->Memberfield;
	Cptr->Memberfield=temp;
}
struct Memberfunclist* Mlookup(struct Classtable* Ctype,char* Name){
	struct Memberfunclist* temp=Ctype->Vfuncptr;
	while(temp!=NULL){
		if(temp->Name!=NULL && strcmp(temp->Name,Name)==0){
			return temp;
		}
		temp=temp->Next;
	}
	return NULL;
}

void Class_Minstall(struct Classtable*Cptr,char*Name,struct Typetable*Type,struct Argstruct *Arglist){

	struct Memberfunclist *temp;
	struct Memberfunclist *Mtemp = Mlookup(Cptr,Name);
	if(Mtemp!=NULL){
		struct Argstruct *Atemp1 = Mtemp->Arglist;
		struct Argstruct *Atemp2 = Arglist;
		while(Atemp1!=NULL && Atemp2!=NULL){
			if(Atemp1->Type!=Atemp2->Type){
				printf("Mismatch in type of arguments can't override\n");
				exit(0);
			}
			Atemp1=Atemp1->Next;
			Atemp2=Atemp2->Next;
		}
		if(Atemp1!=NULL || Atemp2!=NULL){
			printf("Mismatch in type of arguments can't override\n");
			exit(0);
		}
		Mtemp->Flabel=Func_count+1;
		Func_count++;
	}
	else{
		temp= (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
		temp->Type=Type;
		temp->Name=Name;
		temp->Arglist=Arglist;
		temp->Flabel=Func_count+1;
		Func_count++;
		temp->Next=Cptr->Vfuncptr;
		Cptr->Vfuncptr=temp;
		temp->Funcposition=Cptr->Methodcount;
		Cptr->Methodcount++;
		if(Cptr->Methodcount>8) {
			printf("Max limit of functions reached\n");exit(0);
		}
	}
}


struct Classtable* Cinstall(char*Name,char *ParentName){

	struct Classtable *temp= (struct Classtable*)malloc(sizeof(struct Classtable));
	if(ParentName==NULL){
		temp->Memberfield=NULL;
		temp->Vfuncptr=NULL;
		temp->Name=Name;
		temp->Class_index=Class_count+1;
		Class_count++;
		temp->Parentptr=NULL;
		temp->Fieldcount = 0;
		temp->Methodcount = 0;
		temp->Next=NULL;
	}
	else{
		struct Classtable *Parentptr = Clookup(ParentName);
		temp->Memberfield=NULL; 
		temp->Name=Name;
		temp->Class_index=Class_count+1;
		Class_count++;
		temp->Parentptr=Parentptr;
		temp->Fieldcount = Parentptr->Fieldcount;
		temp->Methodcount = Parentptr->Methodcount;
		temp->Next=NULL;
		struct Memberfunclist *Mtemp = Parentptr->Vfuncptr;
		struct Memberfunclist *Vhead = NULL,*Vtemp,*Vtail;
		while(Mtemp!=NULL){

			Vtemp = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
			Vtemp->Type = Mtemp->Type;
			Vtemp->Name = Mtemp->Name;
			Vtemp->Arglist = Mtemp->Arglist;
			Vtemp->Flabel = Mtemp->Flabel;
			Vtemp->Funcposition = Mtemp->Funcposition;
			Vtemp->Next = NULL;
			if(Vhead==NULL){
				Vhead=Vtemp;
				Vtail=Vtemp;
			}
			else{
				Vtail->Next=Vtemp;
				Vtail=Vtemp;
			}
			Mtemp=Mtemp->Next;
		}
		temp->Vfuncptr = Vhead;
	}
	if(Chead==NULL){
		Chead=temp;
		Ctail=temp;
	}
	else{
		Ctail->Next=temp;
		Ctail=temp;
	}
	return temp;
}

void Ginstall(struct Typetable *Type,struct Classtable *Ctype,int Node,char* Name,int Size,struct Argstruct *Arglist){
	struct Gsymbol *temp= (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->Type=Type;
	temp->Ctype=Ctype;
	temp->Node=Node;
	temp->Name=Name;
	temp->Size=Size;
	temp->Arglist=Arglist;
	if(Node==NODE_FUN){
		temp->Flabel=Func_count+1;
		Func_count++;
	}
	else if(Ctype!=NULL){
		temp->Binding=Global_binding+1;
		Global_binding+=2;
	}
	else{
		temp->Binding=Global_binding+1;
		Global_binding+=Size;
	}
	if(Ghead==NULL){
		Ghead=temp;
		Gtail=temp;
	}
	else{
		Gtail->Next=temp;
		Gtail=temp;
	}
}

void Linstall_var(struct Typetable* Type,char *Name){
	struct Lsymbol *temp=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	temp->Type=Type;
	temp->Name=Name;
	temp->Binding=Local_var+1;
	Local_var++;
	if(Lhead==NULL){
		Lhead=temp;
		Ltail=temp;
	}
	else{
		Ltail->Next=temp;
		Ltail=temp;
	}
}

void Linstall_arg(struct Typetable* Type,char *Name){
	struct Lsymbol *temp=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	temp->Type=Type;
	temp->Name=Name;
	temp->Binding=-(Arg_count+3);
	Arg_count++;
	if(Lhead==NULL){
		Lhead=temp;
		Ltail=temp;
	}
	else{
		Ltail->Next=temp;
		Ltail=temp;
	}
}

struct Gsymbol* Glookup(char* Name){
	struct Gsymbol* temp=Ghead;
	while(temp!=NULL){
		if(strcmp(temp->Name,Name)==0){
			return temp;
		}
		temp=temp->Next;
	}
	return NULL;
}

struct Lsymbol* Llookup(char* Name){
	struct Lsymbol* temp= Lhead;
	while(temp!=NULL){
		if(strcmp(temp->Name,Name)==0){
			return temp;
		}
		temp=temp->Next;
	}
	return NULL;
}




struct Fieldlist* Flookup(struct Typetable* Type,char* Name){
	struct Fieldlist* temp=Type->Field;
	while(temp!=NULL){

		if(temp->Name!=NULL && strcmp(temp->Name,Name)==0){
			return temp;
		}
		temp=temp->Next;
	}
	return NULL;
}
struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char* Name){
	while(Ctype!=NULL){
		struct Fieldlist* temp=Ctype->Memberfield;
		while(temp!=NULL){

			if(temp->Name!=NULL && strcmp(temp->Name,Name)==0){
				return temp;
			}
			temp=temp->Next;
		}
		Ctype=Ctype->Parentptr;
	}
	return NULL;
}



void Fieldset(){
	struct Typetable* temp=Thead,*temp1;
	struct Fieldlist* Ftemp;
	while(temp!=NULL){
		// printf("Type: %s\n",temp->Name);
		Ftemp=temp->Field;
		while(Ftemp!=NULL){
			temp1=Tlookup(Ftemp->Typename);
			if(temp1==NULL){
				printf("Type Not declared\n");
				exit(0);
			}
			Ftemp->Type=temp1;
			// printf("MEM Type : %s , Name: %s Fieldposition : %d\n",temp1->Name,Ftemp->Name,Ftemp->Fieldposition);
			Ftemp=Ftemp->Next;
		}
		// printf("\n\n");
		temp=temp->Next;
	}
}

void Final_setup(){
	Arg_count=0;
	Local_var=0;
	Lhead=NULL;
	Ltail=NULL;
}
