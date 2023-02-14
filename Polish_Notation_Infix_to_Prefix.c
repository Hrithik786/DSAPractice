//Infix to Prefix
#include<stdio.h>
#include<math.h>
#include<string.h>

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
    
    char prefix[20];
    float ans;
    printf("please enter correct Prefix expression:\n");
    scanf("%s",&prefix);
    ans=evaluate(prefix);
    printf("\nanswer is %.2f",ans);
    return 0;
}

float evaluate(char prefix[]){

struct stack s;
int i;
char ch;
float op1,op2,result;
s.tos=-1;
for (i=strlen(prefix)-1; i>=0 ; i--)
    {
        ch=prefix[i];
        if(isoperand(ch)==1)
        {
            //ch=ch(float); // typecasting
        push(&s,ch-48);  
        }
        else{
             op1 =pop(&s);
             op2 =pop(&s);
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