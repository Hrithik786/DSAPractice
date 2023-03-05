#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; //self referential structure
};

void append(struct node **, int);
void display(struct node*);

int main()
{
    struct node *start = NULL;
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    display(start);
     
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
    (*ps)=p;
    return;
}
temp=*ps;
while (temp->next!=NULL){
    temp=temp->next;
}
temp->next=p;
}

void display(struct node *p){
if(p==NULL){
    printf("List is Empty ");
    return;
}
while(p->next!=NULL){
    printf("\nData = %d",p->data);
    p=p->next;
}
}
