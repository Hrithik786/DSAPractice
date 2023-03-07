#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //self referential structure
};

void append(struct node **, int);
void display(struct node *);

int main()
{
    int ch,x;
    struct node *start = NULL;
    
do{
    printf("\nHELLO BOSS\n\n\n1.Append\n2.Display\n");
    scanf(" %d",&ch);
    switch(ch)
    {
    case 1:
    printf("\nPlease Enter Element you want to Append\n");
    scanf(" %d",&x);
    append(&start,x);
    break;

    case 2:
    display(start);
    ch=1;
    break;

    default:
    printf("\nPlease Enter Valid Input");
    break;
    }
}while (ch!=2);
return 0;
}

void append(struct node **ps,int x){
struct node *p,*temp;
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL){
    printf("\nInsufficent Memory");
    return;
}
p->data=x;
p->next=NULL;

if (*ps==NULL){
    *ps=p;
    printf("\nAppended Element Successfully",(*ps)->data);
    return;
}
temp=*ps;
while (temp->next!=NULL){
    temp=temp->next;
}
temp->next=p;
printf("\nAppended Element  Successfully",temp->data);
}

void display(struct node *p){
if(p==NULL){
    printf("List is Empty ");
    return;
}
int c=0;
while(p!=NULL){
    printf("\nData = %d",p->data);
    p=p->next;
    c++;
    printf("\ncount nodes =  %d",c);
}
}
