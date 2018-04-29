struct labelnode
{
	int line;
	char label[10];
	struct nodetype *link;
};

struct labelnode *labeltable=NULL,*labelend=NULL;


void insertlabel(char *str,int number);

int replacelabel(char *str);

