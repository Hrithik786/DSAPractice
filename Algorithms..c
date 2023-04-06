#include<stdio.h>


void check(int arr[]);  //for checking wheather the array is sorted or not
int linearsearch(int arr[], int); //declaration
int binarysearch(int arr[], int); 
void bubblesort(int arr[]);
void inspace(int arr[]); //Auxilliary algorithm

int main(){
    
    int ch,x,i;
    int arr[10]={10,20,30,52,25,85,74,96,547,54};
    printf("\n1.Check Wheather the array is sorted or not\n2.linear search\n3.binary search\n4.bubble sort\n5.Inspace array reversal(Auxilliary Algo)\n");
    scanf(" %d",&ch);
    do
    {
        switch (ch)
        {
        case 1:
            check(arr);
            break;
        case 2:
        printf("\nEnter a Element:\n");
        scanf(" %d",&x);
        x = linearsearch(arr,x);
        if (x!=-1)
            printf("\nElement Found at Position: %d",x);
        
        break;

        case 3:
        printf("\nEnter Element:\n");
        scanf(" %d",&x);
        x=binarysearch(arr,x);
        printf("\nElement found at %d Position",x);
        break;

        default:
        printf("\nInvalid Input Try Again!!!");
            break;
        }
    } while (ch!=5);
    
    return 0;
}
int lengthof(int arr[]){
    int i;
    for( i=0 ; arr[i] != '\0' ; i++ );
    return i;
}

void check(int arr[]){
    int i,ans=1; // we are assuming that array is sorted
    
    for ( i = 0; i < lengthof(arr)-1 ; i++){
        if (arr[i] > arr[i+1]){
        ans=0;
        break;
        }
        else if (arr[i] < arr[i+1])
           ans=1;
    }
    printf(ans==0 ? "\nArray is Sorted" : "\nArray isn't Sorted");
}
int linearsearch(int arr[],int x){
    for (int i = 0; i < lengthof(arr); i++)
    {
        if (arr[i]==x)
            return i;   
    }
    printf("\nElement Not Found");
    return -1;
}
int binaryserch(int arr[],int x){
    //array must be sorted
    int left = 0;
    int right = lengthof(arr);
    int mid = ( left+right)/2;
    while (left < right)
    {
        if (x==arr[mid])
        return mid;
        else if (x > arr[mid])
        left=mid+1;
        else if (x < arr[mid])
        right=mid-1;

        mid= (left+right)/2;
    }
    return -1;
}