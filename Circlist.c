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
    int x,ch;
    struct doubly *head=NULL;

    do
    {
        printf("\nHello Boss Enter Element what you wanna do\n");
        printf("1.Append\n2.display\n");
        scanf(" %d",&ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter Element to Append\n");
            scanf(" %d",&x);
            append(&head,x);
            break;
        
        case 2:
        display(head);
        break;

        default:
        printf("\nInvalid Input");
            break;
        }
    } while (ch!=3);
    
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
    int count=0;
    while (temp->next!=*phead){
    temp=temp->next;       
    printf("count %d \n",count++);
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