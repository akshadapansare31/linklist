#include<stdio.h>
#include"doublylist.h"
int main()
{
	int ch;
	struct node*list=NULL;
do
{
	printf("/n 1-create \n 2-disp ");
	printf("enter choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:list=create(list);
		       break;
		case 2:disp(list);
		       break;
	}
}while(ch<3);
}
