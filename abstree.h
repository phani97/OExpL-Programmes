#define TRUE 				1
#define FALSE 				0
#define NODE_VOID 			2
#define NODE_RET 			3
#define NODE_ID_ASGN 		4
#define NODE_ARR_ASGN 		5
#define NODE_FIELD_ASGN 	6
#define NODE_INITIALIZE 	7
#define NODE_ID_ALLOC		8
#define NODE_FIELD_ALLOC	9
#define NODE_ID_FREE		10
#define NODE_FIELD_FREE		11
#define NODE_ID_READ		12
#define NODE_ARR_READ		13
#define NODE_FIELD_READ		14
#define NODE_WRITE			15
#define NODE_IF 			16
#define NODE_IF_ELSE		17
#define NODE_WHILE			18
#define NODE_FIELD 			19
#define NODE_PLUS			20
#define NODE_SUB			21
#define NODE_MUL			22
#define NODE_DIV			23
#define NODE_MOD			24
#define NODE_NE 			25
#define NODE_EQ				26
#define NODE_LT 			27
#define NODE_LE 			28
#define NODE_GT				29
#define NODE_GE 			30
#define NODE_NUM			31
#define NODE_ID_EXPR		32
#define NODE_ID 			33
#define NODE_ARR_EXPR		34
#define NODE_ARRAY 			35
#define NODE_T 				36
#define NODE_F 				37
#define NODE_FIELD_EXPR		38
#define NODE_FUNC			39
#define NODE_ID_EQ			40
#define NODE_ID_NE			41
#define NODE_FIELD_EQ		42
#define NODE_FIELD_NE		43
#define NODE_ID_NULL		44
#define NODE_FIELD_NULL		45
#define NODE_FIELD_ID		46
#define NODE_OBJID_NEW      47
#define NODE_OBJFIELD_NEW   48
#define NODE_OBJID_DELETE   49
#define NODE_OBJFIELD_DELETE  50
#define NODE_FIELD_METHOD   51
#define NODE_SELF_METHOD	52
#define NODE_ID_METHOD 		53
#define NODE_SELF_ID		54
#define NODE_STRVAL         55
#define NODE_ID_ASGN_CLASS 	56
#define NODE_FIELD_ASGN_CLASS	57
#define NODE_ID_NULL_CLASS	58
#define NODE_FIELD_NULL_CLASS	59


union Constant
{
    int intval;
    char* strval;
};
struct Tnode{
	struct Typetable *Type; //saving entry of var from type table
	struct Classtable *Ctype;
	int Node; //for statements
	char *Name; //to store name of ID
	union Constant *Value; //store constants like NUM
	struct Tnode* Arglist; //storing Arguments of Function
	struct Tnode* Obj;
	struct Gsymbol* Gentry; //storing entry for global declarations
	struct Lsymbol* Lentry; //storing entry of local variable
	struct Tnode *Ptr1,*Ptr2,*Ptr3; //for if-else stmts
	struct Tnode* Next; 

};
union Constant cons;
struct Tnode* Treecreate(struct Typetable *Type,struct Classtable *Ctype,int Node,char* Name,union Constant *Value,struct Tnode* Arglist,
								struct Tnode* Ptr1,struct Tnode* Ptr2,struct Tnode* Ptr3);

