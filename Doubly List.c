//Implementing Doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct doubly{
    struct doubly *prev;
    int data;
    struct doubly *next;
};

void append(struct doubly **,int);
void display(struct doubly*);
void delfirst(struct doubly **);
void delany(struct doubly **,int);
void dellast(struct doubly **);

int main(){
    struct doubly *head=NULL;

    append(&head,-9656);
    append(&head,110);
    append(&head,20);
    append(&head,80);
    display(head);
    delfirst(&head);
    display(head);
    dellast(&head);
    display(head);
    main();
    return 0;

}
void append(struct doubly **ph,int x){
    struct doubly *p = (struct doubly *)malloc(sizeof(struct doubly));
    p->data=x;
    p->next=NULL; 
    p->prev=NULL; //preventing from becoming Dangling pointer
    int count=0;

    if (*ph==NULL){
        *ph=p;
        printf("\nFirst Node added Successfully, Node = %d",count++);
        return;
    }
    struct doubly *temp;
    for (temp=*ph ; temp->next!=NULL ; temp=temp->next); //traversing
    p->prev=temp;
    temp->next=p;
    printf("\nNode Added Successfully %d, Node = %d ",p->data,count++);    
}
void display(struct doubly *ph){
    if (ph==NULL)
    {
        printf("\nDoubly is Empty");
        return;
    }
    while (ph!=NULL)
    {
        printf("\nData = %d ",ph->data);
        ph=ph->next;
    } 
}
void delfirst(struct doubly **ph){
    if (*ph==NULL){
        printf("\nDoubly is Empty");
        return;
    }
    struct doubly *p=*ph;
    *ph=(*ph)->next;
    (*ph)->prev=NULL; //preventing from becoming dangling pointer
    free(p);
    printf("\nFirst Node deleted Successfully");
}
void dellast(struct doubly **ph){
    if (*ph==NULL){
        printf("\nDoubly is Empty");
        return;
    }
    for (;ph!=NULL;*ph=(*ph)->next);  // traversing
    struct doubly *p=(*ph)->prev;    //temp pointer for storing prev node address
    p->next=NULL;  //initialising NULL to previous node
    free(*ph);
    printf("\nLast Element Deleted Successfully");
}