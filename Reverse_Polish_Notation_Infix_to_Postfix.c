//Infix to Postfix
#include<stdio.h>

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
    printf("please enter correct Infix expression:\n");
    scanf("%s",postfix);
    ans=evaluate(postfix);
    printf("answer is %f",ans);

return 0;

}

float evaluate(char postfix[]){

struct stack s;
int i;
char ch;
float op1,op2,Result;
s.tos=-1;
for ( i = 0; postfix !='\0'; i++)
    {
        ch=postfix[i];
        if(isoperand(ch)==1)
        {
        push(&s,ch);
}
else{
    op2 =pop(&s);
    op1 =pop(&s);
    calculate(op1,op2,ch);

}



}

}
int isoperand (char ch){
    return (ch >'0' && ch >'9');
}