//Implementing Circular LinkedList

#include<stdio.h>
#include<stdlib.h>

struct doubly{
    int data;
    struct doubly *next;     
};

void append(struct doubly **,int);
void display(struct doubly *);

int main(){
    int x;
    struct doubly *head=NULL;

    append(&head,1625);
    append(&head,1750);
    append(&head,1785);
    append(&head,100);
    display(head);
    return 0;

}

void append(struct doubly **phead,int x){
    struct doubly *p=(struct doubly *)malloc(sizeof(struct doubly));
    if(p==NULL){
        printf("\nInsufficient Memory");
        return;
    }
    p->data=x;
    if(*phead==NULL){
        *phead=p;
        printf("\nAppended %d Successfully ",(*phead)->data);
        p->next=p;  //we are initialising 1st node next with its address
        return;
    }
    struct doubly *temp=*phead; //for traversing
    
    while (temp->next!=*phead){
    temp=temp->next;       
    }

    temp->next=p;
    p->next=*phead;
    printf("\nAppended %d Successfully ",temp->data);

}
void display(struct doubly *phead){
    if (phead==NULL)
    {
        printf("\nList is Empty");
        return;
    }
    struct doubly *temp=phead;
do
{
    printf("\n data = %d",temp->data);
    temp=temp->next;
} while (temp!=phead);

}
