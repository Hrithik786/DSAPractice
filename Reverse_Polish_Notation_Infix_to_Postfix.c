//Infix to Postfix
#include<stdio.h>
//#include<math.h>
struct stack
{
    float arr[10];
    int tos;
};

void push(struct stack *, float);
float pop(struct stack *);
int isoperand(char);
float calculate(float,float,char);
float evaluate(char[]);

int main(){
    
    char postfix[20];
    float ans;
    printf("please enter correct POSTFIX expression:\n");
    scanf("%s",&postfix);
    ans=evaluate(postfix);
    printf("\nanswer is %f",ans);
    return 0;
}

float evaluate(char postfix[]){

struct stack s;
int i;
char ch;
float op1,op2,result;
s.tos=-1;
for ( i = 0; postfix[i] != '\0'; i++)
    {
        ch=postfix[i];
        if(isoperand(ch)==1)
        {
            //ch=ch(float); // typecasting
        push(&s,ch-48);  
        }
        else{
             op2 =pop(&s);
             op1 =pop(&s);
             result = calculate(op1,op2,ch);
             push(&s,result);
             }
    }
    result=pop(&s);
    return result;
}
int isoperand (char ch){
    return (ch >='0' && ch <='9');
}

void push(struct stack *p,float f){
if(p->tos==10){
    printf("\nSTACK OVERFLOW");
    return;
}
p->tos++;
p->arr[p->tos]=f;
}
float pop(struct stack *p){
float x;
if (p->tos==-1){
    printf("\nSTACK UNDERFLOW");
    return 0.0;
    }
x=p->arr[p->tos];
p->tos--;
    return x;
}
float calculate(float op1,float op2,char ch){
    switch (ch)
    {
    case '+': return (op1+op2);
    case '-' : return (op1-op2);
    case '*': return (op1*op2);
    case '/': return (op1/op2);
    //case '%': return modf((op1(double)),(op2(double)));
    //case '$': return powf(op1,op2);   
    default: return 0.0;
    }
}