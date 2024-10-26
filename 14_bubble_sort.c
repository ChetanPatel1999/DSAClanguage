//bubble short code 
#include <stdio.h>
void bubble_sort(int arr[], int size)
{
    int i, j, temp,swapped;
    for (i = 0; i < size - 1; i++)
    {
        swapped=0;
        for (j = 0; j < size - (i + 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped=1;
            }
        }
        if(swapped==0)break;
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
    int arr[] = {12, 3, 2, 56, 78, 44, 345};
    display(arr, 7);
    bubble_sort(arr, 7);
    printf("after sorting..... \n");
    display(arr, 7);
}
