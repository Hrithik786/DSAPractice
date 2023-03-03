//Implementing Linear Queue (Static)

#include<stdio.h>
#define s 5

struct Queue{
    int arr[s];
    int front,rear;
};

void Enqueue(struct Queue *,int);
int Dequeue(struct Queue *);

int main(){
    struct Queue q;
    q.front=0;
    q.rear=-1;
    int ch,n;
do{
    printf("\n1. Enqueue\n2. Dequeue\n");
    scanf(" %d",&ch);
    switch(ch)
    {
        case 1:
        printf("\nEnter Element to Enqueue");
        scanf(" %d",&n);
        Enqueue(&q,n); 
        break;

        case 2:
        n=Dequeue(&q);
        if(n!=0)
        printf("\n Dequeued Value is %d",n);
        break;
        
        default: printf("\nPlease Enter Valid Input");
        break;
    }
}while(ch!=2); 
    return 0;
}

void Enqueue(struct Queue *p, int n){
if(p->rear==s-1){
    printf("\nQueue Overflow");
    return ;
}
p->rear++;
p->arr[p->rear]=n;
printf("\nEnqueued Element is %d ",n);
};

int Dequeue(struct Queue *p){
    if(p->front > p->rear){
        printf("\nQueue Underflow");
        return 0;
    }
    int n = p->arr[p->front];
    p->front+=1;
    return n;
}
