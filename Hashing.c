//Implement Hashing && Collision resolution Technique
//hashing i have done in java language b'cos it's easy for me 
//link 
//Linear Probing
//Quadratic Probing

#include<stdio.h>
#include<stdlib.h>
#define size 20

void linearProbing(int[],int k);
int hash(int,int);

int main(){
    
    int key,element;
    int Hashtable[size]={0}; 
do{
    
    printf("Enter a roll no.\n");
    scanf(" %d",&element);
    key = hash(element,size);
    if (Hashtable[key]==0)
    {
    Hashtable[key] = element;
    printf("\nElement Inserted %d at %d ",element,key);
    }else
    {
        linearProbing(Hashtable,key);
    }
    }while (element!=0);
    return 0;

}

int hash(int element,int s){
return (element % s);
}

void linearProbing(int arr[],int key){
    arr[++key];
}
