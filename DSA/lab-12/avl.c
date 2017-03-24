#include<stdio.h>
#include<stdlib.h>
struct node
{       int data,ht;
        struct node *left,*right;
};
struct node *root=NULL;
void insert(struct node *p,int data);
void preorder(struct node *p);
void postorder(struct node *p);
void inorder(struct node *p);
void avl(struct node *p);
int height(struct node *p);
int bf(struct node *p);
main()
{       int n,data,f=0;
        printf("\nEnter Root Value:");
        scanf("%d",&data);
        struct node *p=(struct node *)malloc(sizeof(struct node ));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        root=p;
        printf("\n1.insert New Data\n2.Pre Order Display\n3.Post Order Display\n4.Inorder Display\n5.Balance\n6.Exit");
        do
        {               printf("\n\tEnter Option:");
                        scanf("%d",&n);
                        switch(n)
                        {       case 1: printf("\nEnter Data:");
                                        scanf("%d",&data);
                                        insert(root,data);
                                        break;
                                case 2:preorder(root);break;
                                case 3:postorder(root);break;
                                case 4:inorder(root);break;
                                case 5://avl(root);break;
				case 6	:exit(0);
                        }
        }while(1);
}
void insert(struct node *p,int data)
{       int f=0;
        printf("\nLeft[0] or Right[1] :");
        scanf("%d",&f);
        if(f==0)
        {       if(p->left==NULL)
                {struct node *p1=(struct node *)malloc(sizeof(struct node ));
                        p1->data=data;
                        p1->right=NULL;
                        p1->left=NULL;
                        p->left=p1;
                }
                else
                {       insert(p->left,data);
                }
        }
        else

        {       if(p->right==NULL)
                {      struct node *p1=(struct node *)malloc(sizeof(struct node ));
                        p1->data=data;
                        p1->right=NULL;
                        p1->left=NULL;
                        p->right=p1;
                }
                else
                {       insert(p->right,data);
                }
        }
	p->ht=height(p);
}
void preorder(struct node *p)
{       if(p!=NULL)
        {       printf("%d %d %d\n",p->data,p->ht,bf(p));
                preorder(p->left);
                preorder(p->right);
        }
}
void postorder(struct node *p)
{       if(p!=NULL)
        {       postorder(p->left);
                postorder(p->right);
                printf("%d ",p->data);
        }
}
void inorder(struct node *p)
{       if(p!=NULL)
        {       inorder(p->left);
                printf("%d ",p->data);
                inorder(p->right);
        }
}
int height(struct node *p)
{
    int lh,rh;
    if(p==NULL)
        return(0);
    
    if(p->left==NULL)
        lh=0;
    else
        lh=1+p->left->ht;
        
    if(p->right==NULL)
        rh=0;
    else
        rh=1+p->right->ht;
    
    if(lh>rh)
        return(lh);
    
    return(rh);
}
int bf(struct node *p)
{
    int lh,rh;
    if(p==NULL)
        return(0);
 
    if(p->left==NULL)
        lh=0;
    else
        lh=1+p->left->ht;
 
    if(p->right==NULL)
        rh=0;
    else
        rh=1+p->right->ht;
 
    return(lh-rh);
}
