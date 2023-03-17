//Implementing Dynamic Stack

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
    int ch,x;
    do
    {
        printf("\nWelcome Boss!! please enter what you wanna do:\n");
        printf("\n1.Push\n2.Pop\n3.Peek\n");
        scanf(" %d",&ch);
        switch (ch)
        {
        case 1:
        printf("\nEnter Element to Push:");
        scanf(" %d",&x);
        push(&tos,x);
        break;

        case 2:
        x=pop(&tos);
        if (x!=-1)
        printf("\nPopped element = %d ",x);        
        break;

        case 3:
        peek(tos);
        ch=1;
        break;
        
        default:
        printf("\nPlease Enter Valid Input!!Try Again");
        break;
        }
    } while (ch!=3);

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
    printf("\nTop Element = %d ",ptos->data);
    return;  
}