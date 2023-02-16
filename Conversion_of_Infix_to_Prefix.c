#include <stdio.h>
#include <string.h>
#define MAX 10
struct Stack
{
    char arr[MAX];
    int tos;

};
void push(struct Stack *,char);
char pop(struct Stack *);
int isoperand(char);
int isempty(struct Stack);
int prcd(char,char);
void convert(char[],char[]);
int main()
{
    char infix[20],prefix[20];
    printf("Enter a valid infix:");
    scanf("%s",infix);
    convert(infix,prefix);
    printf("Converted exp is %s",prefix);
    return 0;
}
void convert(char infix[20],char prefix[20])
{
    int i,j=0;
    struct Stack S;
    char ch;
    char op1,op2;
    int ans;
    S.tos=-1;
    for(i=strlen(infix)-1;i>=0;i--)
    {
        ch=infix[i];
        if(isoperand(ch)==1)
        {
            prefix[j]=ch;
            j++;
        }
        else
        {
            while(isempty(S)==0)
            {
                ans=prcd(ch,S.arr[S.tos]);
                if(ans==1)
                    break;
                prefix[j]=pop(&S);
                j++;
            }
            push(&S,ch);
        }
    }
    while(isempty(S)==0)
    {
        prefix[j]=pop(&S);
        j++;
    }
    prefix[j]='\0';
    strrev(prefix);
}
void push(struct Stack *p,char x)
{
    if(p->tos==MAX-1)
    {
        printf("Stack Overflow");
        return;
    }
    p->tos++;
    p->arr[p->tos]=x;
}
char pop(struct Stack *p)
{
    char x;
    if(p->tos==-1)
    {
        printf("Stack Underflow");
        return 0;
    }
    x=p->arr[p->tos];
    p->tos--;
    return x;
}
int isoperand(char ch)
{
    if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')||(ch>='0' && ch<='9'))
        return 1;
    return 0;
}
int isempty(struct Stack S)
{
    return (S.tos==-1);
}
int prcd(char op1,char op2)
{
    if(op2=='$')
        return 0;
    else if(op1=='$')
        return 1;
    else if(op2=='/'||op2=='*'||op2=='%')
        return 0;
    else if(op1=='/'||op1=='*'||op1=='%')
        return 1;
    else if(op2=='+'||op2=='-')
        return 0;
    else
            return 1;

}
