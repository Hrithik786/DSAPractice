#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //self referential structure
};

void append(struct node **, int);
void display(struct node *);
int searchnode(struct node *, int);
void prepend(struct node **,int);
void addatpos(struct node**,int,int);

int main()
{
    int pos,ch,x;
    struct node *start = NULL;
    
do{
    printf("\nHELLO BOSS\n\n1.Append\n2.Display\n3.Search Position of Node\n4.Prepend\n5.Add at Position\n");
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
    ch=1;        //for looping
    break;
    
    case 3:
    printf("\nEnter a data which you wanna search\n");
    scanf(" %d",&x);
    x = searchnode(start,x);
    printf("\nposition = %d",x); 
    ch=1;     
    break;

    case 4:
    printf("\nEnter a data which you wanna Add at First node\n");
    scanf(" %d",&x);
    prepend(&start,x);
    ch=1;
    break;

    case 5:
    pos=0;
    printf("\nEnter a data as well as position (respectively) which you wanna Add\n");
    scanf(" %d %d",&x,&pos);
    addatpos(&start,x,pos);
    ch=1;
    break;

    default:
    printf("\nPlease Enter Valid Input");
    break;
    }
}while (ch!=4);
return 0;
}
int searchnode(struct node *p,int x){
int c=0;
if(p==NULL){
    printf("\nList is Empty");
    return c;
}
while (p!=NULL)
{
    c++;
    if (p->data==x)
    return c;    
    p=p->next;
}
    return c;
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
void prepend(struct node **ps ,int x){
struct node *temp,*pre = (struct node*)malloc(sizeof(struct node));
if (pre==NULL)
{
    printf("\nInsufficient Memory");
    return;
}

pre->next=NULL;
pre->data=x;

if(*ps==NULL){
    *ps=pre;
    printf("\nElement Added Sucessfully = %d",(*ps)->data);
    return;
}
temp=*ps;  //start->temp
*ps=pre;  //start->new node
pre->next=temp;//node ->connect ->linkedist
printf("\nElement Added Successfully");
free(temp);//check it
}
void addatpos(struct node **ps,int x,int pos){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    if (node==NULL)
    {
        printf("\nInsufficient Memory");
        return;
    }
    node->data=x;
    node->next=NULL;
    if (*ps==NULL)
    {
    printf("\nNo Nodes Found in this List This is b'cause we are adding this Element as A First Node");
    *ps=node;
    printf("\nElement Added Successfully = %d",(*ps)->data);
    return;
    }
    int count=0;  //issues from here
    struct node *prev,*temp=NULL;
    temp=*ps;
    while(temp->next!=NULL){
        count++;
        prev=temp;
        if (count==pos){
            prev->next=node;
            node->next=temp;
            printf("\nNode Added Successfully at Position %d",count);
            return;
        }
        temp=temp->next;
        } 
        printf("\nList is Small, Position not found, Add some nodes then try Again,Thank You!!");
        return;
}
