#include<stdio.h>
#include<math.h>
#define max 10

struct stack{
    char arr[max];
    int tos;
};
void push(struct stack * ,char);
char pop(struct stack*);
int isOperand(char);
int isEmpty(struct stack);
int prcd(char,char);//op1>op2----->push(),,,,,,,op1<=op2--------->pop()
void convert(char[],char[]);

int main(){
    char Infix[20],Postfix[20];
    printf("\nPlease Enter Correct Infix Expression:");
    scanf("%s",Infix);
    convert(Infix,Postfix);
    printf("\nPostfix Expresson is %s",Postfix);

    return 0;
}
//--------------------------------------------------------------------------------
void convert(char Infix[],char Postfix[]){
struct stack s;
s.tos=-1;
char ch,opn;
int i,j=0;
int ans;
for( i = 0; Infix[i]!='\0' ; i++)
{
    ch=Infix[i];
    if (isOperand(ch)==1){
        Postfix[j]=ch;
        j++;
    }else{
            while(isEmpty(s)==0){
                ans=prcd(ch,s.arr[s.tos]);
                if(ans==1)
                    break;
            opn=pop(&s);
            Postfix[j]=opn;
            j++;                
        }
        push(&s,ch);
        }
}
while (isEmpty(s)==0)
{
    opn=pop(&s);
    Postfix[j]=opn;
    j++;
}
Postfix[j]='\0';
}
//------------------------------------------------------------------------------------------
int prcd(char op1,char op2){
if (op2=='$')
    return 0;
else if(op1=='$')
    return 1;
else if (op2=='/'||op2=='*'||op2=='%')
    return 0;
else if(op1=='/'||op1=='*'||op1=='%')
    return 1;
else if (op2=='+'||op2=='-')
return 0;
else
return 1;

}

void push(struct stack *p,char ch){
    if(p->tos==max-1){
        printf("\n STACK OVERFLOW");
        return ;
    }
    p->tos++;
    p->arr[p->tos]=ch;
}

char  pop(struct stack *p){
    char ch;
    if(p->tos==-1){
        printf("\nSTACK UNDERFLOW");
        return 0 ;
    }
    ch=p->arr[p->tos];
    p->tos--;
    return ch;
}

int isOperand(char ch){
    return ((ch>='0'&&ch<='9')||ch>='a' && ch<='z'||ch>='A' && ch<='Z');
}
int isEmpty(struct stack s){
    return (s.tos==-1);
}