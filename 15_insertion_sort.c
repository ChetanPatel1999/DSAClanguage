//bubble short code 
#include <stdio.h>
void insertion_sort(int arr[], int size)
{
   //3, 12, |  2, 56, 78, 345, 44
   int i,j,key;
   for(i=1;i<size;i++)
   {
     key=arr[i];
     j=i-1;//1
     while(j>=0 && arr[j]>key)
     {
       arr[j+1]=arr[j];
       j--;
     }
     arr[j+1]=key;
   }
}
void display(int arr[], int size)
{
    int i;
    printf("array element are : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void main()
{
    int arr[] = {12, 3, 2, 56, 78, 345, 44};
    display(arr, 7);
    insertion_sort(arr, 7);
    printf("after sorting..... \n");
    display(arr, 7);
}
