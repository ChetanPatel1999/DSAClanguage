#include <stdio.h>
void slection_sort(int arr[], int size)
{
    int i, j,temp,minindex;
    for (i = 0; i < size-1; i++)
    {
        minindex=i;
        for (j = i+1; j < size; j++)
        {
            if(arr[minindex]>arr[j])
            {
                minindex=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
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
    slection_sort(arr, 7);
    printf("after sorting..... \n");
    display(arr, 7);
}
