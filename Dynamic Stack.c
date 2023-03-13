#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

void push(struct stack **,int);
int pop(struct stack **);
void peek(struct stack *);

int main(){
    struct stack *tos=NULL;
    push(&tos, 10);
    push(&tos,-98);
    push(&tos,780);
    push(&tos,50);
    peek(tos);
    
    while(tos!=NULL)
    printf("\npopped element = %d",pop(&tos));

    return 0;
}
void push(struct stack **ptos,int x){
    struct stack *p = (struct stack *)malloc(sizeof(struct stack));
    if (p==NULL){
        printf("\nInsufficient Memory");
        return;
    }
    p->data=x;
    p->next=NULL;    
    if (*ptos==NULL){
        *ptos=p;
        printf("\nPushed %d successfully",x);
        return;
    }
    p->next=*ptos;
    *ptos=p;
    printf("\nPushed %d successfully",x);

}
int pop(struct stack **ptos){
    int x;
    if(*ptos==NULL){
        printf("\nStack Underflow");
        return -1;
    }
    x=(*ptos)->data;
    struct stack *temp = *ptos;
    *ptos=(*ptos)->next;    
    free(temp);    
    return x;
}
void peek(struct stack *ptos){
    if (ptos==NULL){
        printf("\nStack is Empty");
        return;
    }
    printf("\nData = %d ",ptos->data);
    return;  
}