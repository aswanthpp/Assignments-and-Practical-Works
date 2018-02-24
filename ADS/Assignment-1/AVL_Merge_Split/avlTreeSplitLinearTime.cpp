// Arvind Ramachandran - 15CO111
//Aswanth P P 	       - 15CO112
// Date : 24-02-2018 


#include<stdio.h>
#include<stdlib.h>
#define width 5
struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
    
};
  
 struct Node * root=NULL;
 struct Node *root1=NULL;
 struct Node *root2=NULL;
int max(int a, int b)
{
    if(a>b)
    	return a;
    else 
    	return b;
}

int getHeight(struct Node *p)
{
    if (p == NULL)
        return 0;
    return p->height;
}
int getHeightDiff(struct Node *p)
{
    if (p == NULL)
        return 0;
    return (getHeight(p->left) - getHeight(p->right));
}

struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 

    x->right = y;
    y->left = T2;
 

    y->height = max(getHeight(y->left), getHeight(y->right))+1;
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
 

    return x;
}
 
struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 

    y->left = x;
    x->right = T2;
 

    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    y->height = max(getHeight(y->left), getHeight(y->right))+1;
 

    return y;
}


 
struct Node* insert(struct Node *p, int value)
{

    if (p == NULL){
    
	    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	    temp->data   = value;
	    temp->left   = NULL;
	    temp->right  = NULL;
	    temp->height = 1;
	    p=temp;  
	    
    }
    if (value < p->data)
        p->left  = insert(p->left, value);
    else if (value > p->data)
        p->right = insert(p->right, value);
    
    p->height = 1 + max(getHeight(p->left),
                           getHeight(p->right));
 
    int heightDiff = getHeightDiff(p);
 
    
    // Left Left Case
    if (heightDiff > 1 && value < p->left->data)
        return rightRotate(p);
 
    // Right Right Case
    if (heightDiff < -1 && value > p->right->data)
        return leftRotate(p);
 
    // Left Right Case
    if (heightDiff > 1 && value > p->left->data)
    {
        p->left =  leftRotate(p->left);
        return rightRotate(p);
    }
 
    // Right Left Case
    if (heightDiff < -1 && value < p->right->data)
    {
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }
 
    
    return p;
}


struct List {
	int x;
	struct List *next;
};
struct List *head=NULL;
int c=0;
void push(struct List *p,int data){
	if(p==NULL){
		p=(struct List *)malloc(sizeof(struct List));
		p->x=data;
		p->next=NULL;
		head=p;
		c++;
	}
	else{
		struct List *temp=(struct List *)malloc(sizeof(struct List)); 
		temp->x=data;
		temp->next=NULL;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
		c++;
	}
}

void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        
        inOrder(root->left);
        push(head,root->data);
        inOrder(root->right);
    }
}
void split(struct Node *p,int key){

	inOrder(root);
	for(struct List *p=head;p!=NULL;p=p->next){
		if(p->x<key){
			root1=insert(root1,p->x);
		}
		else {
			root2=insert(root2,p->x);
		}
	}
} 
 
void display(struct Node *Node,int space){
	if(Node==NULL){
		return ;
	}
	space+=width;
	display(Node->right,space);
	printf("\n\n");
	for(int i=width;i<space;i++){
		printf(" ");
	}
	printf("%d\n",Node->data);
	display(Node->left,space);
}


int main()
{
  FILE *inp=fopen("tree.txt","r");
  int len;
  fscanf(inp,"%d",&len);  
  for(int i=0;i<len;i++){
  	int x;
  	fscanf(inp,"%d",&x);
  	root=insert(root,x);
  }
 
  printf("\n\n\t\t\tInitial Tree\n\t\t\t===============\n");
  display(root,0);
  	
 
  int n;
  printf("Enter key :");
  scanf("%d",&n);
 
	
  split(root,n); 
 
  printf("\n\n\t\t\tFirst Tree\n\t\t\t===============\n");
  display(root1,0);
  
  printf("\n\n\t\t\tSecond Tree\n\t\t\t===============\n");
  display(root2,0); 
 
  
  
  
  return 0;
}
