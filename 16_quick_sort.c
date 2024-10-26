// quick short code
#include <stdio.h>
int partician(int arr[], int low, int high)
{
    int pivot = arr[low], i, j, temp;
    i = low + 1;
    j = high;
    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    while(i<j);
    temp=arr[j];
    arr[j]=arr[low];
    arr[low]=temp;
    return j;
}
void quick_sort(int arr[], int low, int high)
{
    int particianIndex;
    if (low < high)
    {
        particianIndex = partician(arr, low, high);
        quick_sort(arr, low, particianIndex - 1);
        quick_sort(arr, particianIndex + 1, high);
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
    int arr[] = {12, 3, 2, 56, 78, 44, 345,1,5,67,89};
    display(arr, 11);
    quick_sort(arr, 0, 11-1);
    printf("after sorting..... \n");
    display(arr, 11);
}
