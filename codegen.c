FILE *fp;
void Initialise_Codegen()
{
	fp=fopen("assemblycode.xsm","w");
	if(fp == NULL)
	{
		printf("Unable to locate file\n");
		exit(1);
	}
	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
      fprintf(fp,"JMP L0\n");
}
void Initialise_Global(){
      
      fprintf(fp,"MOV SP,%d\n",Global_binding);
      fprintf(fp,"PUSH R1\n");
      fprintf(fp,"CALL F0\n");
      fprintf(fp,"INT 10\n");
}
void Install_Vfuntable(){
      fprintf(fp,"L0:\n");
      struct Classtable *Ctemp;
      struct Memberfunclist *Vfunctemp;
      Ctemp=Chead;
      while(Ctemp!=NULL){
            Vfunctemp = Ctemp->Vfuncptr;
            while(Vfunctemp!=NULL){
                  fprintf(fp,"MOV R0,%d\n",4096+Ctemp->Class_index*8+Vfunctemp->Funcposition);
                  fprintf(fp,"MOV [R0],F%d\n",Vfunctemp->Flabel);
                  Vfunctemp = Vfunctemp->Next;
            }
            Global_binding+=8;
            Ctemp=Ctemp->Next;
      }
}

int counter = -1,label = 0;

int getlabel()
{
	return ++label;
}

void freereg()
{
	if(counter >= 0)
		counter--;
}

int getreg()
{
	if(counter < 12)
		return ++counter;
	else
	{
		printf("Running out of registers\n");
		exit(1);
	}
}

void Codegen_func(int Flabel,struct Tnode *Root){
	if(fp == NULL)
	{
		printf("Unable to locate file\n");
		exit(1);
	}
	fprintf(fp,"F%d:\n",Flabel);//exit(0);
	fprintf(fp,"PUSH BP\n");
	fprintf(fp,"MOV BP,SP\n");
	fprintf(fp,"ADD SP,%d\n",Local_var);
	counter = -1;
	int y=Codegen(Root);//exit(0);
}


int Codegen(struct Tnode* Root){
	int r1,r2,l1,l2,number,offset,i,r3;
	struct Tnode* temp;
	struct Fieldlist* temp1;
	struct Memberfunclist *temp2;
	if(Root==NULL) {
		printf("Root is NULL\n");
		exit(0);
	}
	switch(Root->Node){
		case NODE_VOID:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			break;
		case NODE_RET:
			r1=Codegen(Root->Ptr1);
			fprintf(fp, "MOV R%d,BP\n", r1+1);
			fprintf(fp, "SUB R%d,2\n", r1+1);
			fprintf(fp, "MOV [R%d],R%d\n",r1+1,r1);
			freereg();
			fprintf(fp, "SUB SP,%d\n",Local_var);
			fprintf(fp, "POP BP\n");
			fprintf(fp, "RET\n");
			break;
		case NODE_ID_ASGN:

			r2=Codegen(Root->Ptr3);
			r1=getreg();
			if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp,"MOV R%d,BP\n",r1);
				fprintf(fp,"ADD R%d,%d\n",r1,Root->Ptr1->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
			}
			fprintf(fp,"MOV [R%d],R%d\n",r1,r2);
			freereg();//exit(0);
			freereg();
			return -1;
			break;
            case NODE_ID_ASGN_CLASS:
                  r2=getreg();
                  fprintf(fp,"MOV R%d,[%d]\n",r2,Root->Ptr3->Gentry->Binding);
                  fprintf(fp,"MOV [%d],R%d\n",Root->Ptr1->Gentry->Binding,r2);
                  fprintf(fp,"MOV R%d,[%d]\n",r2,Root->Ptr3->Gentry->Binding+1);
                  fprintf(fp,"MOV [%d],R%d\n",Root->Ptr1->Gentry->Binding+1,r2);
                  freereg();//exit(0);
                  return -1;
                  break;
		case NODE_ARR_ASGN:
			r1=Codegen(Root->Ptr2);
			r2=getreg();
			fprintf(fp,"MOV R%d,%d\n",r2,Root->Ptr1->Gentry->Binding);
			fprintf(fp,"ADD R%d,R%d\n",r1,r2);
			freereg();
			r2=Codegen(Root->Ptr3);
			fprintf(fp,"MOV [R%d],R%d\n",r1,r2);
			freereg();
			freereg();
			return -1;
			break;
		case NODE_FIELD_ASGN:
			// fprintf(fp,"BRKP\n");
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr3);
			fprintf(fp,"MOV [R%d],R%d\n",r1,r2);
			freereg();//exit(0);
			freereg();
			// fprintf(fp,"BRKP\n");
			return -1;
			break;
            case NODE_FIELD_ASGN_CLASS:
                  r1=Codegen(Root->Ptr1);
                  r2=Codegen(Root->Ptr3->Ptr1);
                  r3=getreg();
                  fprintf(fp,"MOV R%d,[R%d]\n",r3,r2);
                  fprintf(fp,"MOV [R%d],R%d\n",r1,r3);
                  fprintf(fp,"ADD R%d,1\n",r2);
                  fprintf(fp,"ADD R%d,1\n",r1);
                  fprintf(fp,"MOV R%d,[R%d]\n",r3,r2);
                  fprintf(fp,"MOV [R%d],R%d\n",r1,r3);
                  freereg();
                  freereg();//exit(0);
                  freereg();
                  // fprintf(fp,"BRKP\n");
                  return -1;
                  break;
		case NODE_INITIALIZE:
			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Heapset\"\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,-1\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"CALL 0\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");

            if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp,"MOV R1,BP\n");
				fprintf(fp,"ADD R1,%d\n",Root->Ptr1->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R1,%d\n",Root->Ptr1->Gentry->Binding);
			}
			fprintf(fp, "MOV [R1],R2\n");
			for(int i=counter;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
			break;
		case NODE_ID_ALLOC:
			r1=getreg();
			if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp,"MOV R%d,BP\n",r1);
				fprintf(fp,"ADD R%d,%d\n",r1,Root->Ptr1->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
			}
			// fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Alloc\"\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,%d\n",Root->Ptr1->Type->Size);
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"CALL 0\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            r2=getreg();
            fprintf(fp, "MOV R%d,R2\n",r2 );
			for(int i=counter-1;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
            fprintf(fp, "MOV [R%d],R%d\n",r1,r2);
            freereg();
            freereg();
			break;
		case NODE_FIELD_ALLOC:
			r1=Codegen(Root->Ptr1);

			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Alloc\"\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,%d\n",Root->Ptr1->Type->Size);
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"CALL 0\n");
            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            r2=getreg();
            fprintf(fp, "MOV R%d,R2\n",r2 );
			for(int i=counter-1;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
            fprintf(fp, "MOV [R%d],R%d\n",r1,r2);
            freereg();
            freereg();
			break;

		case NODE_OBJID_NEW:
                  r1=getreg();

                        fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
                  // fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
                  for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Alloc\"\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,%d\n",8);
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"CALL 0\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            r2=getreg();
            fprintf(fp, "MOV R%d,R2\n",r2);
                  for(int i=counter-1;i>=0;i--)
            {
                  fprintf(fp,"POP R%d\n",i);
            }
            fprintf(fp, "MOV [R%d],R%d\n",r1,r2);
            fprintf(fp,"ADD R%d,1\n",r1);
            fprintf(fp,"MOV [R%d],%d\n",r1,Root->Ptr2->Ctype->Class_index*8+4096);
            freereg();
            freereg();
                  break;


		case NODE_OBJFIELD_NEW :
                  r1=Codegen(Root->Ptr1);

                  for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Alloc\"\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,%d\n",8);
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"CALL 0\n");
            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            r2=getreg();
            fprintf(fp, "MOV R%d,R2\n",r2 );
                  for(int i=counter-1;i>=0;i--)
            {
                  fprintf(fp,"POP R%d\n",i);
            }
            fprintf(fp, "MOV [R%d],R%d\n",r1,r2);
            fprintf(fp,"ADD R%d,1\n",r1);
            fprintf(fp,"MOV [R%d],%d\n",r1,Root->Ptr2->Ctype->Class_index*8+4096);
            freereg();
            freereg();
                  break;

		case NODE_OBJID_DELETE :
                  for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Free\"\n");
            fprintf(fp,"PUSH R2\n");
            //fprintf(fp,"MOV R1,%d\n",Root->Ptr2->Gentry->Binding);

                  fprintf(fp,"MOV R1,%d\n",Root->Ptr1->Gentry->Binding);

            fprintf(fp, "MOV R2,[R1]\n" );
            fprintf(fp, "PUSH R2\n" );
            fprintf(fp, "MOV [R1],-1\n");
            fprintf(fp,"ADD R1,1\n");
            fprintf(fp,"MOV [R1],-1\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            //fprintf(fp,"PUSH R3\n");
                  fprintf(fp,"CALL 0\n");
            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");


                  for(int i=counter-1;i>=0;i--)
            {
                  fprintf(fp,"POP R%d\n",i);
            }
            break;
		case NODE_OBJFIELD_DELETE:
                  for(int i=0;i<=counter;i++)
            {
                  fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Free\"\n");
            fprintf(fp,"PUSH R2\n");
            r1=Codegen(Root->Ptr1);
            r2=getreg();
            fprintf(fp,"MOV R%d,[R%d]\n",r2,r1);
            fprintf(fp, "PUSH R%d\n",r2 );
            fprintf(fp, "MOV [R%d],-1\n",r1 );
            fprintf(fp,"ADD R%d,1\n",r1);
            fprintf(fp,"MOV [R%d],-1\n",r1);
            freereg();
            freereg();
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            //fprintf(fp,"PUSH R3\n");
            fprintf(fp,"CALL 0\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");


                  for(int i=counter-1;i>=0;i--)
            {
                  fprintf(fp,"POP R%d\n",i);
            }

                  break;


		case NODE_ID_FREE:

			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Free\"\n");
            fprintf(fp,"PUSH R2\n");
            //fprintf(fp,"MOV R1,%d\n",Root->Ptr2->Gentry->Binding);
            if(Root->Ptr2->Lentry!=NULL){
				fprintf(fp,"MOV R1,BP\n");
				fprintf(fp,"ADD R1,%d\n",Root->Ptr2->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R1,%d\n",Root->Ptr2->Gentry->Binding);
			}
            fprintf(fp, "MOV R2,[R1]\n" );
            fprintf(fp, "PUSH R2\n" );
            fprintf(fp, "MOV [R1],-1\n" );
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            //fprintf(fp,"PUSH R3\n");

            fprintf(fp,"CALL 0\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");

            if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp,"MOV R1,BP\n");
				fprintf(fp,"ADD R1,%d\n",Root->Ptr1->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R1,%d\n",Root->Ptr1->Gentry->Binding);
			}
			fprintf(fp, "MOV [R1],R2\n");
			for(int i=counter-1;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
			break;
		case NODE_FIELD_FREE:
			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
            fprintf(fp,"MOV R2,\"Free\"\n");
            fprintf(fp,"PUSH R2\n");
            r1=Codegen(Root->Ptr2);
            r2=getreg();
            fprintf(fp,"MOV R%d,[R%d]\n",r2,r1);
            fprintf(fp, "PUSH R%d\n",r2 );
            fprintf(fp, "MOV [R%d],-1\n",r1 );
            freereg();
            freereg();
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            //fprintf(fp,"PUSH R3\n");
            fprintf(fp,"CALL 0\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp,"MOV R1,BP\n");
				fprintf(fp,"ADD R1,%d\n",Root->Ptr1->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R1,%d\n",Root->Ptr1->Gentry->Binding);
			}
			fprintf(fp, "MOV [R1],R2\n");
			for(int i=counter-1;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
			break;


		case NODE_ID_READ:
			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }

            if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp,"MOV R1,BP\n");
				fprintf(fp,"ADD R1,%d\n",Root->Ptr1->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R1,%d\n",Root->Ptr1->Gentry->Binding);
			}

            fprintf(fp,"MOV R2,7\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,-1\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"INT 6\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");

            for(int i=counter;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
			break;
		case NODE_ARR_READ:
			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
			r1=getreg();
			offset=Codegen(Root->Ptr2);
			fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
			fprintf(fp,"ADD R%d,R%d\n",r1,offset);
			fprintf(fp,"MOV R1,R%d\n",r1);
			freereg();
			freereg();

			fprintf(fp,"MOV R2,7\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,-1\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"PUSH R1\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"INT 6\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");

            for(int i=counter;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
			break;
		case NODE_FIELD_READ:
			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
			fprintf(fp,"MOV R2,7\n");
            fprintf(fp,"PUSH R2\n");
            fprintf(fp,"MOV R2,-1\n");
            fprintf(fp,"PUSH R2\n");
            r1=Codegen(Root->Ptr1);
            fprintf(fp,"PUSH R%d\n",r1);
            freereg();
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"PUSH R3\n");
            fprintf(fp,"INT 6\n");

            fprintf(fp,"POP R2\n");
            fprintf(fp,"POP R1\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");
            fprintf(fp,"POP R3\n");

            for(int i=counter;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
			break;
		case NODE_WRITE:
			for(int i=0;i<=counter;i++)
            {
                fprintf(fp,"PUSH R%d\n",i);
            }
			number=Codegen(Root->Ptr1);

                  int reg1=getreg();
			//fprintf(fp,"PUSH R%d\n",number);
			//freereg();
			//fprintf(fp,"MOV R1,SP\n");

			fprintf(fp,"MOV R%d,5\n",reg1);
			fprintf(fp,"PUSH R%d\n",reg1);
			fprintf(fp,"MOV R%d,-2\n",reg1);
			fprintf(fp,"PUSH R%d\n",reg1);
			fprintf(fp,"PUSH R%d\n",number);
                  freereg();
                  freereg();
			fprintf(fp,"PUSH R0\n");
                  fprintf(fp,"PUSH R0\n");
                  fprintf(fp,"INT 7\n");

                  fprintf(fp,"POP R2\n");
                  fprintf(fp,"POP R1\n");
                  fprintf(fp,"POP R3\n");
                  fprintf(fp,"POP R3\n");
                  fprintf(fp,"POP R3\n");
                

			for(int i=counter;i>=0;i--)
            {
            	fprintf(fp,"POP R%d\n",i);
            }
			break;
		case NODE_IF  :
			/*printf("---IF---");*/
			l1 = getlabel();
			number = Codegen(Root -> Ptr1);
			//fprintf(fp,"BRKP\n");
			fprintf(fp, "JZ R%d , L%d\n",number,l1);
			number = Codegen(Root -> Ptr2);
			fprintf(fp, "L%d:\n",l1);
			freereg();
			break;
		case NODE_IF_ELSE:
			/*printf("---IF_ELSE---");*/
			number = Codegen(Root -> Ptr1);
			l1 = getlabel();
			l2 = getlabel();
			fprintf(fp, "JZ R%d , L%d\n",number,l1);
			number = Codegen(Root -> Ptr2);
			fprintf(fp, "JMP L%d\n",l2);
			fprintf(fp, "L%d:\n",l1);
			number = Codegen(Root -> Ptr3);
			fprintf(fp, "L%d:\n",l2);
			freereg();
			break;
		case NODE_WHILE :
			//printf("---WHILE----");exit(0);
			l1 = getlabel();
			l2 = getlabel();
			fprintf(fp, "L%d:\n",l1);
			number = Codegen(Root -> Ptr1);
			fprintf(fp, "JZ R%d , L%d\n",number,l2);
			number = Codegen(Root -> Ptr2);
			fprintf(fp, "JMP L%d\n",l1);
			fprintf(fp, "L%d:\n",l2);
			freereg();
			break;
		case NODE_FIELD:
			//fprintf(fp,"BRKP\n");
			r1=Codegen(Root->Ptr1);
			fprintf(fp, "MOV R%d,[R%d]\n",r1,r1);
			temp1 = Flookup(Root->Ptr1->Type,Root->Ptr2->Name);
			//printf("%d\n",Fieldposition);
			fprintf(fp, "ADD R%d,%d\n",r1,temp1->Fieldposition);
			return r1;
			break;

		case NODE_SELF_ID:
			r1=getreg();
			fprintf(fp, "MOV R%d,BP\n",r1);
			fprintf(fp, "ADD R%d,%d\n",r1,-Arg_count-2-1-1 );
			fprintf(fp, "MOV R%d,[R%d]\n",r1 ,r1);
			temp1 = Class_Flookup(Root->Ptr1->Ctype,Root->Ptr2->Name);
			fprintf(fp, "ADD R%d,%d\n",r1,temp1->Fieldposition);
			return r1;
			break;
		case NODE_FIELD_ID:
			r1=getreg();
			if(Root->Ptr1->Lentry!=NULL){

				fprintf(fp,"MOV R%d,BP\n",r1);
				fprintf(fp,"ADD R%d,%d\n",r1,Root->Ptr1->Lentry->Binding);

			}
			else{
				fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
			}
			fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
			temp1 = Flookup(Root->Ptr1->Type,Root->Ptr2->Name);
			//printf("%d\n",Fieldposition);
			fprintf(fp, "ADD R%d,%d\n",r1,temp1->Fieldposition);
			return r1;
			break;
		case NODE_PLUS:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"ADD R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_SUB:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"SUB R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_MUL:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"MUL R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_DIV:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"DIV R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_MOD:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"MOD R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_NUM:
			r1=getreg();
			fprintf(fp,"MOV R%d,%d\n",r1,Root->Value->intval);
			return r1;
			break;
		case NODE_ID_EXPR:
			r1=getreg();
			if(Root->Lentry!=NULL){

				fprintf(fp,"MOV R%d,BP\n",r1);
				fprintf(fp,"ADD R%d,%d\n",r1,Root->Lentry->Binding);

			}
			else{
				fprintf(fp,"MOV R%d,%d\n",r1,Root->Gentry->Binding);
			}
			fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
			return r1;
			break;
		case NODE_ARR_EXPR:
			r1=getreg();
			offset=Codegen(Root->Ptr2);
			fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
			fprintf(fp,"ADD R%d,R%d\n",r1,offset);
			fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
			freereg();
			return r1;
			break;
		case NODE_FUNC:
			for(i=0;i<=counter;i++){
				fprintf(fp,"PUSH R%d\n",i);
			}
			temp=Root->Arglist;
			number=0;
			while(temp!=NULL){
				r1=Codegen(temp);//printf("hi\n");
				fprintf(fp,"PUSH R%d\n",r1);
				number++;temp=temp->Next;
				freereg();
			}
			fprintf(fp,"PUSH R0\n");
			fprintf(fp,"CALL F%d\n",Root->Ptr1->Gentry->Flabel);
			fprintf(fp,"POP R0\n");
			fprintf(fp,"SUB SP,%d\n",number);
			r1=getreg();
			fprintf(fp,"MOV R%d,R0\n",r1);
			for(i=counter-1;i>=0;i--){
				fprintf(fp,"POP R%d\n",i);
			}
			return r1;
			break;
		case NODE_ID_METHOD:
                  //fprintf(fp, "BRKP\n");
                  for(i=0;i<=counter;i++){
                        fprintf(fp,"PUSH R%d\n",i);
                  }
                  r1=getreg();
                  fprintf(fp,"MOV R%d,[%d]\n",r1,Root->Obj->Gentry->Binding);
                  fprintf(fp, "PUSH R%d\n",r1 );
                  fprintf(fp,"MOV R%d,[%d]\n",r1,Root->Obj->Gentry->Binding+1);
                  fprintf(fp, "PUSH R%d\n",r1 );
                  temp=Root->Arglist;
                  number=0;
                  while(temp!=NULL){
                        r2=Codegen(temp);//printf("hi\n");
                        fprintf(fp,"PUSH R%d\n",r2);
                        number++;temp=temp->Next;
                        freereg();
                  }
                  fprintf(fp,"PUSH R0\n");
                  temp2=Mlookup(Root->Obj->Ctype,Root->Ptr1->Name);
                  fprintf(fp,"ADD R%d,%d\n",r1,temp2->Funcposition);
                  fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                  fprintf(fp,"CALL R%d\n",r1);
                  freereg();
                  r1=getreg();
                  fprintf(fp,"POP R%d\n",r1);
                  fprintf(fp,"SUB SP,%d\n",number+2);
                  for(i=counter-1;i>=0;i--){
                        fprintf(fp,"POP R%d\n",i);
                  }
                  return r1;
                  break;
		case NODE_FIELD_METHOD:
                  // fprintf(fp, "BRKP\n");
                  for(i=0;i<=counter;i++){
                        fprintf(fp,"PUSH R%d\n",i);
                  }
                  r1=Codegen(Root->Obj);
                  r2=getreg();
                  fprintf(fp, "MOV R%d,[R%d]\n",r2,r1);
                  fprintf(fp, "PUSH R%d\n",r2 );
                  fprintf(fp, "ADD R%d,1\n",r1);
                  fprintf(fp, "MOV R%d,[R%d]\n",r1,r1);
                  fprintf(fp, "PUSH R%d\n",r1);
                  freereg();
                  temp=Root->Arglist;
                  number=0;
                  while(temp!=NULL){
                        r2=Codegen(temp);//printf("hi\n");
                        fprintf(fp,"PUSH R%d\n",r2);
                        number++;temp=temp->Next;
                        freereg();
                  }
                  fprintf(fp,"PUSH R0\n");
                  temp2=Mlookup(Root->Obj->Ctype,Root->Ptr1->Name);
                  fprintf(fp,"ADD R%d,%d\n",r1,temp2->Funcposition);
                  fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                  fprintf(fp,"CALL R%d\n",r1);
                  freereg();
                  r1=getreg();
                  fprintf(fp,"POP R%d\n",r1);
                  fprintf(fp,"SUB SP,%d\n",number+2);
                  for(i=counter-1;i>=0;i--){
                        fprintf(fp,"POP R%d\n",i);
                  }
                  return r1;
                  break;

            case NODE_SELF_METHOD:
                  // fprintf(fp, "BRKP\n");
                  for(i=0;i<=counter;i++){
                        fprintf(fp,"PUSH R%d\n",i);
                  }
                  //r1=Codegen(Root->Obj);
                  r1 = getreg();
                  r2 = getreg();
                  fprintf(fp, "MOV R%d,BP\n",r1);
                  fprintf(fp, "ADD R%d,%d\n",r1,-Arg_count-2-1-1);
                  fprintf(fp, "MOV R%d,[R%d]\n",r2,r1 );
                  fprintf(fp, "PUSH R%d\n",r2);
                  fprintf(fp, "ADD R%d,1\n",r1);
                  fprintf(fp, "MOV R%d,[R%d]\n",r1,r1);
                  fprintf(fp, "PUSH R%d\n",r1);
                  freereg();
                  temp=Root->Arglist;
                  number=0;
                  while(temp!=NULL){
                        r2=Codegen(temp);//printf("hi\n");
                        fprintf(fp,"PUSH R%d\n",r2);
                        number++;temp=temp->Next;
                        freereg();
                  }
                  fprintf(fp,"PUSH R0\n");
                  temp2=Mlookup(Root->Obj->Ctype,Root->Ptr1->Name);
                  fprintf(fp,"ADD R%d,%d\n",r1,temp2->Funcposition);
                  fprintf(fp,"MOV R%d,[R%d]\n",r1,r1);
                  fprintf(fp,"CALL R%d\n",r1);
                  freereg();
                  r1=getreg();
                  fprintf(fp,"POP R%d\n",r1);
                  fprintf(fp,"SUB SP,%d\n",number+2);
                  for(i=counter-1;i>=0;i--){
                        fprintf(fp,"POP R%d\n",i);
                  }
                  return r1;
                  break;

		case NODE_GT:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"GT R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_GE:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"GE R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_LT:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"LT R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_LE:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"LE R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_EQ:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"EQ R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_NE:
			r1=Codegen(Root->Ptr1);
			r2=Codegen(Root->Ptr2);
			fprintf(fp,"NE R%d,R%d\n",r1,r2);
			freereg();
			return r1;
			break;
		case NODE_T:
			r1=getreg();
			fprintf(fp,"MOV R%d,1\n",r1);
			return r1;
			break;
		case NODE_F:
			r1=getreg();
			fprintf(fp,"MOV R%d,0\n",r1);
			return r1;
			break;
		case NODE_FIELD_EXPR:
			r1=Codegen(Root->Ptr1);
			fprintf(fp, "MOV R%d,[R%d]\n",r1,r1);
			return r1;
			break;
		case NODE_ID_EQ:
			//checking is it null....
			r1=getreg();
			//fprintf(fp,"INT 10\n");
			// fprintf(fp, "BRKP\n");
			if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp, "MOV R%d,BP\n",r1 );
				fprintf(fp, "ADD R%d,%d\n",r1,Root->Ptr1->Lentry->Binding );
			}
			else{
				fprintf(fp, "MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding );
			}
			fprintf(fp, "MOV R%d,[R%d]\n",r1,r1);

			r2 = getreg();
			fprintf(fp, "MOV R%d,-1\n",r2);
			fprintf(fp, "EQ R%d,R%d\n",r1,r2);
			// fprintf(fp,"BRKP\n");
			freereg();
			return r1;
			break;
		case NODE_ID_NE:
			//checking is it null....
			r1=getreg();
			if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp, "MOV R%d,BP\n",r1 );
				fprintf(fp, "ADD R%d,%d\n",r1,Root->Ptr1->Lentry->Binding );
			}
			else{
				fprintf(fp, "MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding );
			}
			fprintf(fp, "MOV R%d,[R%d]\n",r1,r1);
			r2 = getreg();
			fprintf(fp, "MOV R%d,-1\n",r2);
			fprintf(fp, "NE R%d,R%d\n",r1,r2);
			// fprintf(fp,"BRKP\n");
			freereg();
			return r1;
			break;
		case NODE_FIELD_EQ:
			r1=Codegen(Root->Ptr1);
			fprintf(fp, "MOV R%d,[R%d]\n",r1,r1 );
			r2 = getreg();
			fprintf(fp, "MOV R%d,-1\n",r2);
			fprintf(fp, "EQ R%d,R%d\n",r1,r2);
			// fprintf(fp,"BRKP\n");
			freereg();
			return r1;
			break;
		case NODE_FIELD_NE:
			r1=Codegen(Root->Ptr1);
			fprintf(fp, "MOV R%d,[R%d]\n",r1,r1 );
			r2 = getreg();
			fprintf(fp, "MOV R%d,-1\n",r2);
			fprintf(fp, "NE R%d,R%d\n",r1,r2);
			// fprintf(fp,"BRKP\n");
			freereg();
			return r1;
			break;
		case NODE_ID_NULL:
			r1=getreg();
			if(Root->Ptr1->Lentry!=NULL){
				fprintf(fp,"MOV R%d,BP\n",r1);
				fprintf(fp,"ADD R%d,%d\n",r1,Root->Ptr1->Lentry->Binding);
			}
			else{
				fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
			}
			fprintf(fp,"MOV [R%d],%d\n",r1,-1);
			freereg();//exit(0);
			return -1;
			break;

            case NODE_ID_NULL_CLASS:
                  r1=getreg();
                  fprintf(fp,"MOV R%d,%d\n",r1,Root->Ptr1->Gentry->Binding);
                  fprintf(fp,"MOV [R%d],-1\n",r1);
                  fprintf(fp,"ADD R%d,1\n",r1);
                  fprintf(fp,"MOV [R%d],-1\n",r1);
                  freereg();//exit(0);
                  return -1;
                  break;

		case NODE_FIELD_NULL:
			r1=Codegen(Root->Ptr1);
			fprintf(fp,"MOV [R%d],%d\n",r1,-1);
			freereg();//exit(0);
			return -1;
			break;

            case NODE_FIELD_NULL_CLASS:
                  r1=Codegen(Root->Ptr1);
                  fprintf(fp,"MOV [R%d],%d\n",r1,-1);
                  fprintf(fp,"ADD R%d,1\n",r1);
                  fprintf(fp,"MOV [R%d],-1\n",r1);
                  freereg();//exit(0);
                  return -1;
                  break;

            case NODE_STRVAL :
                  r1 = getreg();
                  fprintf(fp, "MOV R%d,\"%s\"\n",r1,(Root ->Value->strval));
                  return r1;
                  break;


		default:
			printf("Missing Node type : %d",Root->Node);exit(0);
			break;
	}
	return -1;
}
