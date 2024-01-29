#include<stdio.h>
#include<stdlib.h>
#define memory (node*)malloc(sizeof(node))
typedef struct node
{
	int data;
    struct node *next;
}node;
node *create(node *list)
{
	int i,n;
	node *newnode, *temp;
	printf("enter limit");
	scanf("%d",&n);
	for(i=0;i<n;i++)
{
	newnode=memory;
	printf("enter value");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(list==NULL)
	{
		list=newnode;
		temp=newnode;
	}
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
}
return list;
}
void disp(struct node *list)
{
	node *temp;
	for(temp=list;temp!=NULL;temp=temp->next)
{
	printf("%d\t",temp->data);
}
}
node *delvalue(struct node *list,int num)
{
	node *temp,*temp1;
	for(temp=list;temp->data!=NULL;temp=temp->next)
{
	if(temp->next->data==num)
	{
		temp1=temp->next;
		break;
	}
}
temp->next=temp1->next;
free(temp1);
return list;
}
int main()
{
	int ch,num;
	node *list=NULL;
do
{
	printf("/n 1-create \n 2-disp \n 3-delete");
	printf("enter choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:list=create(list);
		       break;
		case 2:disp(list);
		       break;
	    case 3:printf("enter number to delete");
	    	   scanf("%d",&num);
	    	   delvalue(list,num);
	    	   break;
	}
}while(ch<4);
}
