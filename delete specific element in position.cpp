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
node *delp(struct node *list,int p)
{
	int i;
	node *temp,*temp1;
	
	if(p==1)
	{
	temp=list;
	list=list->next;
	free(temp);
	}
	else
	{
		for(i=1,temp=list;i<(p-1)&&temp->next!=NULL;i++,temp=temp->next);
		temp1=temp->next;
		temp->next=temp1->next;
		free(temp1);
	}
	return list;
}
int main()
{
	int ch,p;
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
	    case 3:printf("enter the position");
	    	   scanf("%d",&p);
	    	   list=delp(list,p);
	    	   break;
	}
}while(ch<4);
}
