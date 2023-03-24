//Implementing Circular LinkedList
//Hello Boss run it on your IDE please 

#include<stdio.h>
#include<stdlib.h>

struct circ{
    int data;
    struct circ *next;     
};

void append(struct circ **,int);
void display(struct circ *);
void delfirst(struct circ **);
void dellast(struct circ **);
//delany which should accecpt int as argument
//insert list always remains Sorted

int main(){
    int x,ch;
    struct circ *head=NULL;

    do
    {
        printf("\nHello Boss Enter Element what you wanna do\n");
        printf("1.Append\n2.Display\n3.Del_first\n4.dellast\n");
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
        
        case 3:
        delfirst(&head);
        break;

        case 4:
        dellast(&head);
        break;

        default:
        printf("\nInvalid Input");
            break;
        }
    } while (ch!=5);
    
    return 0;

}

void append(struct circ **phead,int x){
    struct circ *p=(struct circ *)malloc(sizeof(struct circ));
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
    struct circ *temp=*phead; //for traversing
    int count=0;
    while (temp->next!=*phead){
    temp=temp->next;       
    printf("count %d \n",count++);//for checking loop is iterating or not
    }

    temp->next=p;
    p->next=*phead;
    printf("\nAppended %d Successfully ",temp->data);

}
void display(struct circ *phead){
    if (phead==NULL)
    {
        printf("\nList is Empty");
        return;
    }
    struct circ *temp=phead;
do
{
    printf("\n data = %d",temp->data);
    temp=temp->next;
} while (temp!=phead);
}
void delfirst(struct circ **ph){
if(*ph==NULL){
    printf("\nList is Empty");
    return;
}
struct circ *p=*ph;
*ph=(*ph)->next;
free(p);
printf("\nFirst Node Removed Successfully");
}
void dellast(struct circ **ph){
if (*ph==NULL)
{
    printf("\nList is Empty");
    return;
}
if ((*ph)->next==*ph)
{
    free(*ph);
    *ph=NULL;
    printf("\nElement Deleted Succesfully");
}
struct circ *prev,*temp;
for (temp=*ph;temp->next!=*ph; temp=temp->next)
{
    prev=temp;
}
free(temp);
prev->next=*ph;
printf("\nElement Deleted Successfully");
}
