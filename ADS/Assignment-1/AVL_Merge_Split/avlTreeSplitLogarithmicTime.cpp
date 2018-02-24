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
  
struct Node *root=NULL;
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

struct Node* getMin(struct Node *p )
{
    while (p->left != NULL)
       	p = p->left;
 
    return p;
}
struct Node* getMax(struct Node *p)
{
     
    while (p->right!= NULL)
       	p = p->right;
    return p;
}


struct Node* remove(struct Node *p, int x)
{
    
    if (p == NULL)
        return p;
 
    if ( x < p->data )
        p->left = remove(p->left,x);
 
    else if( x > p->data )
        p->right = remove(p->right,x);
 
    else
    {
        
        if( (p->left == NULL) || (p->right == NULL) )
        {
            struct Node *temp = p->left ? p->left :p->right;
 
            // Both child NULL
            if (temp == NULL)
            {
                temp = p;
                p = NULL;
            }
            // One child NULL
            else 
             *p = *temp; 
        }
        else
        {
            struct Node* temp = getMin(p->right);
            p->data = temp->data;
            p->right = remove(p->right, temp->data);
        }
    }
    if (p == NULL)
      return p;
 
    p->height = 1 + max(getHeight(p->left),
                           getHeight(p->right));
 
    int heightDiff = getHeightDiff(p);
 
    
    // Left Left Case
    if (heightDiff > 1 && getHeightDiff(p->left) >= 0)
        return rightRotate(p);
 
    // Left Right Case
    if (heightDiff > 1 && getHeightDiff(p->left) < 0)
    {
        p->left =  leftRotate(p->left);
        return rightRotate(p);
    }
 
    // Right Right Case
    if (heightDiff < -1 && getHeightDiff(p->right) <= 0)
        return leftRotate(p);
 
    // Right Left Case
    if (heightDiff < -1 && getHeightDiff(p->right) > 0)
    {
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }
 
    return p;
}



struct Node *mergeNewRoot(struct Node *root1, struct Node *root2, struct Node *temp)
{
    if(root1==NULL)
    {
        return root2;
    }
    if(root2==NULL)
    {
        return root1;
    }
    if(root1->height-root2->height<=1&&root1->height-root2->height>=-1)
    {
        temp->left=root1;
        temp->right=root2;
        temp->height=max(root1->height,root2->height)+1;
        return temp;
    }
    else if(root1->height>root2->height)
    {
        struct Node *t = mergeNewRoot(root1->right,root2,temp);
        root1->right= t;
        int heightDiff = getHeightDiff(t);
        int key = t->data;
        if (heightDiff > 1 && key < t->left->data)
        return rightRotate(t);
        if (heightDiff < -1 && key > t->right->data)
        return leftRotate(t);
        if (heightDiff > 1 && key > t->left->data)
        {
            t->left =  leftRotate(t->left);
            return rightRotate(t);
        }
        if (heightDiff < -1 && key < t->right->data)
        {
            t->right = rightRotate(t->right);
            return leftRotate(t);
        }
    }
    else if(root1->height<root2->height)
    {
        struct Node *t =mergeNewRoot(root2->right,root1,temp);
        root2->right = t;
        int heightDiff = getHeightDiff(t);
        int key = t->data;
        if (heightDiff > 1 && key < t->left->data)
        return rightRotate(t);
        if (heightDiff < -1 && key > t->right->data)
        return leftRotate(t);
        if (heightDiff > 1 && key > t->left->data)
        {
            t->left =  leftRotate(t->left);
            return rightRotate(t);
        }
        if (heightDiff < -1 && key < t->right->data)
        {
            t->right = rightRotate(t->right);
            return leftRotate(t);
        }
    }
}


struct Node* merge(struct Node *root1,struct Node *root2)
{
    struct Node *max =getMax(root1);
    root1 = remove(root1,max->data);
    struct Node *tree = mergeNewRoot(root1,root2,max);
    return tree; 
}




void split(struct Node *p, int x)
{
   
    if(p==NULL)
    {
        root1=NULL;
        root2=NULL;
   
    }
    else if(x<p->data)
    {
        split(p->left,x);
        if(root2==NULL)
        {
            struct Node *temp = p;
            temp->left=NULL;
            temp->right= p->right;
            root2=temp;
        }
        else if(root2->data<p->right->data)
        {
            struct Node *r = mergeNewRoot(root2,p->right,p);
            root2=r;
        }
        else if(root2->data>p->right->data)
        {
            struct Node *r = mergeNewRoot(p->right,root2,p);
            root2=r;
        }
    //    return l;
    }
    else if(x>p->data)
    {
        split(p->right,x);
        if(root1==NULL)
        {
            struct Node *temp=p;
            temp->right=NULL;
            temp->left=p->left;
            root1=temp;;
        }
        else if(root1->data<p->left->data)
        {
            struct Node *r = mergeNewRoot(root1,p->left,p);
            root1=r;
        }
        else if(root1->data>p->left->data)
        {
            struct Node *r = mergeNewRoot(p->left,root1,p);
            root1=r;
        }
      //  return l;
    }
    else if(x==p->data)
    {
        root1=p->left;
        root2=p->right;
        //return l;
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
