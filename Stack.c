#include<stdio.h>

struct stack{
int arr[5];
int tos;
};
void push (struct stack *, int );
int pop (struct stack *);    
void peek();

int main(){
    struct stack s;
    s.tos=-1;
    char ch;
    int x;
    a:
    printf("\n hello please choose what do yo want to do \n1.push\n2.pop\n3.peek");
    scanf("%d",&ch);
    do{
    switch(ch)
    {
   case 1:
       printf("\nplease enter an element to push:\n");
       scanf("%d",&x);
       push(&s,x);
       goto a;
    break;

   case 2:
       x=pop(&s);
        if(x>0)
        printf("\npopped element = %d",x);
        goto a;
    break;

   case 3:
       peek(&s);
       goto a;
    break;

    default :
        printf("\n Invalid Input please enter a valid Input ,Thank you");
        goto a;
    }
    }while(ch!=3);

return 0;
}
void push(struct stack *p, int n ){
if(p->tos>5){
    printf("\nSTACK OVERFLOW");
    return;
}
p->tos++;
p->arr[p->tos]=n;
printf("pushed element =%d",n);
return;
}

int pop (struct stack *p){   
int x;
if(p->tos<=-1){
    printf("\n STACK UNDERFLOW");
    return -1;
}
x=p->arr[p->tos];
p->tos--;
return x;
}
void peek(struct stack *p){
if(p->tos>-1){
    printf("TOP element = %d",p->arr[p->tos]);
}
else
    printf("Empty stack");
    return ;
}


configure
