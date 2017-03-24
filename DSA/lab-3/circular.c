#include <stdio.h>
#include <stdlib.h>

struct node
{
 int data;
 struct node *address;
};

void createnode(struct node *,int ,int );
void deletenode(struct node *,int );
void display(struct node *);
struct node *header = NULL;

void main()
{
 int ch,x,pos;
 printf("1. INSERTION  2. DELETION  3. DISPLAY  4. EXIT\n");
 for(;;)
 {
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
   ptr1->address = ptr1;
   header = ptr1;
 }
 else
 {
   ptr2 = (struct node *)malloc(sizeof(struct node));
   ptr2->data = x;
   ptr2->address = header;
   if(pos==1)
   {
    for(;;)
   {
    if(ptr1->address == header)
    break;
    ptr1 = ptr1->address;
   }
    ptr2->address = header;
    header = ptr2;
    ptr1->address = header;
   }
   else
   {
   for(;;)
   {
    if(ptr1->address==header || c==(pos-1))
    break;
    ptr1 = ptr1->address;
    c++;
   }
   ptr2->address = ptr1->address;
   ptr1->address = ptr2;
 }
}
}

void deletenode(struct node *ptr1,int pos)
{
 struct node *temp1;
  int c = 1;
  
if(ptr1==NULL)
  return;
  else
  {
   if(pos==1)
   {
    temp1 = header;
    for(;;)
   {
    if(ptr1->address == header)
    break;
    ptr1 = ptr1->address;
   }
    ptr1->address = temp1->address;
    header = ptr1->address;
    free(temp1);
   }
  else
  {
   while(pos!=c)
   {
    temp1=ptr1;
    ptr1 = ptr1->address;
    c++;
  }
  temp1->address = ptr1->address;
   free(ptr1);
}
        }
}

void display(struct node *ptr)
{
 do
 {
   printf("%d->",ptr->data);
   ptr = ptr->address;
 }
 while(ptr!=header);


printf("*\n");
}

