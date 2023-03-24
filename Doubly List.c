//Implementing Doubly linked list
//hello BOSS !!! please run it on your IDE

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
//void delany(struct doubly **,int);
void dellast(struct doubly **);

int main(){
    struct doubly *head=NULL;
    int ch,x;
    do
    {
        printf("\nHello BOSS!!! Enter what you want");
        printf("\n1.Append\n2.Display\n3.Delfirst\n4.DelAny(under maintainance)\n5.Dellast\n");
        scanf(" %d",&ch);
        switch (ch)
        {
            case 1:
            printf("\nEnter a value to append:\n");
            scanf(" %d",&x);
            append(&head,x);
            break;

            case 2:
            display(head);
            break;

            case 3:
            delfirst(&head);
            break;

            case 4:
            //delany(&head);
            break;

            case 5:
            dellast(&head);
            ch=1;
            break;

        default:
        printf("\nInvalid Input!!! please try Again");
            break;
        }
    } while (ch!=5);
    
    return 0;

}
void append(struct doubly **ph,int x){
    struct doubly *p = (struct doubly *)malloc(sizeof(struct doubly));
    p->data=x;
    p->next=NULL; 
    p->prev=NULL; //preventing from becoming Dangling pointe
    if (*ph==NULL){
        *ph=p;
        printf("\nFirst Node added Successfully");
        return;
    }
    struct doubly *temp;
    for (temp=*ph ; temp->next!=NULL ; temp=temp->next); //traversing
    p->prev=temp;
    temp->next=p;
    printf("\nNode Added Successfully %d",p->data);    
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
    if ((*ph)->next==NULL)
    {
        free(*ph);
        *ph=NULL;
        printf("\nLast Element Deleted Successfully");
        return;
    }
    struct doubly *p,*t;
    for (t=*ph ; t->next!=NULL ; t=t->next);  // traversing
    p=t->prev;    //temp pointer for storing prev node address
    p->next=NULL;  //initialising NULL to previous node
    free(t);
    printf("\nLast Element Deleted Successfully");
}