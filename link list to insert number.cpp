#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* insert(struct Node* list, int data) 
{
    struct Node* new_Node=newNode(data);
    if (list==NULL || data<list->data) 
    {
        new_Node->next = list;
        list=new_Node;
    } 
    else
    {
            struct Node* temp1 = list;
            while (temp1->next != NULL && data > temp1->next->data) 
            {
            temp1= temp1->next;
            }
        new_Node->next = temp1->next;
        temp1->next = new_Node;
    }
    return list;
}

void display(struct Node* list) 
{
    struct Node* temp = list;
    while (temp != NULL) 
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
int main() 
{
    struct Node* list= NULL;
    int i,num,n;
     printf("Enter limit = ");   
     scanf("%d",&n);
    for(i=0;i<n;i++)
     {
         scanf("%d",&num);
         list= insert(list,num);
     }


    display(list);
}
