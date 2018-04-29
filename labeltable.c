void insertlabel(char *str,int number)
{
	struct labelnode *temp;
	temp=(struct labelnode *)malloc(sizeof(struct labelnode));
	temp->line = number;

	strcpy(temp->label,str);
	temp->link=NULL;
	if(labeltable==NULL)
	{
		labeltable=temp;
		labelend=temp;
	}
	else
	{
		labelend->link=temp;	
		labelend=temp;
	}
}

int replacelabel(char *str)
{
	char str1[100];
	strcpy(str1,str);
    strcat(str1,":\n");
	struct labelnode *temp;
	temp=labeltable;
	
	while(temp!=NULL)
	{
		if(strcmp(temp->label,str1)==0)
		{
			return temp->line;
		}
		temp=temp->link;
	}
}

