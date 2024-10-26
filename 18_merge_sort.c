// bubble short code
#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid+1, k = low, b[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}
void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    int arr[] = {44, 31, 54, 5,98, 7, 9, 345};
    display(arr, 8);
    merge_sort(arr, 0,7);
    printf("after sorting..... \n");
    display(arr, 8);
}
