#include <stdio.h>
#include <stdlib.h>

struct node
{
 int data;
 struct node *next;
 struct node *prev;
};

void createnode(struct node *,int ,int );
void deletenode(struct node *,int );
void display(struct node *);
struct node *header = NULL;
int cnt=0;

void main()
{
 int ch,x,pos;
 for(;;)
 {
  printf("1. INSERTION  2. DELETION  3. DISPLAY  4. EXIT\n");
  printf("Enter your choice\n");
  scanf("%d",&ch);

  switch(ch)
  {
   case 1 : printf("Enter Element and Position\n");
	    scanf("%d %d",&x,&pos);
	    createnode(header,x,pos);
	    break;
   case 2 : printf("Enter Node to Delete\n");
	    scanf("%d",&x);
	    deletenode(header,x);
	    break;
   case 3 : printf("DISPLAYING THE LIST\n");
	    display(header);
	    break;
   case 4 : exit(0);
  }
 }
}
void createnode(struct node *ptr1,int x,int pos)
{
 int c = 1;
 struct node *ptr2;
 if(ptr1==NULL)
 {
   ptr1 = (struct node *)malloc(sizeof(struct node));
   ptr1->data = x;
   ptr1->next = NULL;
   ptr1->prev = NULL;
   header = ptr1;
	cnt++;
 }
 else
 {
   ptr2 = (struct node *)malloc(sizeof(struct node));
   ptr2->data = x;
   ptr2->next = NULL;
   if(pos==1)
   {
    ptr2->next = header;
    header->prev = ptr2;
    header = ptr2;
	cnt++;
   }
   else
   {
   for(;;)
   {
    if(ptr1->next==NULL || c==(pos-1))
    break;
    ptr1 = ptr1->next;
    c++;
   }
   ptr2->next = ptr1->next;
   ptr1->next = ptr2;
   ptr2->prev = ptr1;
	cnt++;
   if(ptr2->next!=NULL)
   ptr2->next->prev = ptr2;
 }
}
}


void deletenode(struct node *ptr1, int pos)
{
   int c=1;
   struct node *temp;
   if(ptr1==NULL)
    return;

   if(pos==1)
   {
    header = ptr1->next;
    header->prev = NULL;
    free(ptr1);
	cnt--;
   }
	else if(pos>cnt)
	{	printf("\nOut of Position Entered\n");
	}
   else
   {
   while(pos!=c)
   {
     temp = ptr1;
     ptr1 = ptr1->next;
     c++;
   }
   temp->next = ptr1->next;
   if(ptr1->next!=NULL)
   ptr1->next->prev = temp;
   free(ptr1);
	cnt--;
}
}

void display(struct node *ptr)
{
 while(ptr!=NULL)
 {
  printf("%d->",ptr->data);
  ptr = ptr->next;
 }
 printf("*\n");
}

