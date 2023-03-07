#include<stdio.h>
#define s 5

struct CQueue{
    int arr[s];
    int front,rear;
};

void Enqueue(struct CQueue *,int);
int Dequeue(struct CQueue *);

int main(){
    struct CQueue q;
    int ch,x;
    q.front=q.rear=-1;
    
do{ 
    printf("\n1. Enqueue \n2. Dequeue\n");
    scanf(" %d",&ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter Element to Enqueue\n");       
        scanf(" %d",&x);
        Enqueue(&q,x);
        break;
    
    case 2:
    x=Dequeue(&q);
    if(x!=-1)
    printf("\nDequeued Element =%d",x);
    ch=1;
    break;

    default:
    printf("Please Enter Valid Input");
    break;
    }
}while (ch!=2);

    return 0;
}
void Enqueue(struct CQueue *p, int n){
    if((p->rear+1)%s==p->front){
        printf("\nQueue Overflow");
        return;
        }
    else if(p->front==-1 && p->rear==-1)
        {
        p->front=p->rear=0;
        p->arr[p->rear]=n;
        printf("\nEnqueued Element  = %d",n);
        }
    else{
        p->rear=(p->rear+1)%s;
        p->arr[p->rear]=n;
        printf("\nEnqueued Element  = %d",n);
         }
}
int Dequeue(struct CQueue *p){
    int y;
    if(p->front==-1)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    else if (p->front==p->rear)
    {
        y = p->arr[p->front];
        printf("\n Dequeued element  = %d",y);
        p->front=p->rear=-1;
        return y;
    }else
    {
        y = p->arr[p->front];
        printf("\n Dequeued element  = %d",y);
        p->front=(p->front+1)%s;
        return y;
        }
        
}