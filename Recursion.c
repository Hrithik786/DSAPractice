#include<stdio.h>

void print_mine(int);
void fact(int);  //declaration

int main(){
    int a=1000;
    print_mine(a);

    printf("\n\n %d",sum(5));

    fact(5);

    return 0;
}

void print_mine( int n){
if (n>0)
{
    printf("\n %d",n);
    print_mine(n-1);  //Tail Recursion//
}
return;
}

int sum(int n){
    if (n<=1)
    {
        return n;
    }
    return n + sum(n-1);
    
}

void fact(int n){
    int facto =1;
    if(n<0) return;
    else{
    printf("\n %d",n);
    facto = facto * fact(n-1);  
    }
    printf(" \n %d ",facto);
}

