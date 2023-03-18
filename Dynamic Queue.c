//Implementing Dynamic Queue
//please run it on your IDE

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

void enqueue(struct Queue **, struct Queue **,int);
int dequeue(struct Queue **, struct Queue **);
void display(struct Queue *,struct Queue *);

int main(){
    struct Queue *front,*rear;
    front=rear=NULL;
    int x,ch;
    do
    {
        printf("\nHello Boss!!\n1.Enqueue\n2.Dequeue\n3.Display\n");
        scanf(" %d",&ch);
        
        switch (ch)
        {
        case 1:
        printf("\nEnter Element What you wanna Insert ");
        scanf(" %d",&x);
        enqueue(&front,&rear,x);
        break;
        
        case 2:
        x=dequeue(&front,&rear);
        if(x!=-1)
        printf("\nDequeued Element = %d ",x);
        break;
        
        case 3:
        display(front,rear);
        ch=1;
        break;

        default:
        printf("\nInvalid Input");
        break;

        }
    } while (ch!=3);
    
    return 0;
}

void enqueue(struct Queue **pf,struct Queue **pr,int y){
    struct Queue *p = (struct Queue*)malloc(sizeof(struct Queue));
    if (p==NULL)
    {
        printf("\n Queue Overflow");
        return ;
    }
    p->data=y;
    p->next=NULL;

    if (*pr==NULL){
        *pf=*pr=p;
        printf("\nFirst Element Inserted Successfully %d",(*pr)->data);
        return;
    }
    (*pr)->next=p;
    *pr=p;
    printf("\nElement Inserted %d",(*pr)->data);
}
int dequeue(struct Queue **pf,struct Queue **pr){
    int x;
    if(*pf==NULL){
        printf("\nQueue Underflow");
        return -1;
    }
    if (*pf==*pr)
    {
        x=(*pf)->data;
        *pf=*pr=NULL;
        return x;
    }
    struct Queue *p=*pf;
    x=p->data;
    *pf=(*pf)->next;
    free(p);
    return x;
}
void display(struct  Queue *f,struct Queue *r){
    if(f==NULL){
        printf("\nQueue is Empty");
        return;
    }
    do{
        printf("\nData = %d",f->data);
        f=f->next;
    }while (f!=r);
}