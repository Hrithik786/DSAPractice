//Implementing Circular Queue
//please run it on your IDE
//so that you may see the OUTPUT

#include<stdio.h>
#define s 5

struct CQueue{
    int arr[s];
    int front,rear;
};

void Enqueue(struct CQueue *,int);
int Dequeue(struct CQueue *);
void display(struct CQueue);

int main(){
    struct CQueue q;
    int ch,x;
    q.front=q.rear=-1;
    
do{ 
    printf("\n1. Enqueue \n2. Dequeue\n3. Display\n");
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
    break;

    case 3:
    display(q);
    ch=1;
    break;

    default:
    printf("Please Enter Valid Input");
    break;
    }
}while (ch!=3);

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
void display(struct CQueue q){
    if(q.front==-1){
        printf("\nQueue is Empty");
        return;
    }
    do{
        printf("\n %d \n",q.arr[q.front]);
        q.front=(q.front+1)%s;
    }while(q.front!=q.rear);
}