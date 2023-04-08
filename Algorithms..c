#include<stdio.h>
# define size 10
void check(int []);                  //for checking wheather the array is sorted or not
int linearsearch(int [], int);       //declaration
int binarysearch(int [], int); 
void bubblesort(int []);
void inspace(int []); //Auxilliary algorithm
int lengthof(int []); //for finding length of array

int main(){
    int ch,x,i;
    int arr[10] = {10,20,30,52,25,85,74,96,547,54};
    printf("\n1.Check Wheather the array is sorted or not\n2.linear search\n3.binary search\n4.bubble sort\n5.Inspace array reversal(Auxilliary Algo)\n6.Display Array\n");
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
            x = binarysearch(arr,x);
            printf("\nElement found at %d Position",x);
            break;
            
            case 6:
            for (int i = 0; i < lengthof(arr) ; i++)
                printf("\n %d",arr[i]);
            break;
                    
            default:
            printf("\nInvalid Input Try Again!!!");
            break;
        }
    } while (ch!=10);

    return 0;
}

int lengthof(int arr[10]){
    int i;
    for( i = 0 ; arr[i] != '\0' ; i++ ); //frequency testing
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
    printf(ans==1 ? "\nArray is Sorted" : "\nArray isn't Sorted");
}
int linearsearch(int arr[], int x){
    for (int i = 0; i < lengthof(arr); i++)
    {
        if (arr[i]==x)
            return i;   
    }
    printf("\nElement Not Found");
    return -1;
}
int binarysearch(int arr[], int x){
    //array must be sorted
    int left = 0;
    int right; 
    right = lengthof(arr);
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