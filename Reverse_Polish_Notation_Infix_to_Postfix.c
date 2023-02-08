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
struct stack s;
int i;
char ch;
float x;
s.tos=-1;

char postfix[20];
printf("please enter correct Infix expression:\n");
scanf("%s",postfix);






    return 0;

}