#include <stdio.h>
void count_sort(int arr[], int size)
{
    int max = 0, i, j;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int count[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    j = 0;
    for (i = 0; i < max + 1; i++)
    {
        while (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
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
    int arr[] = {12, 3, 2, 56, 78, 3, 455, 44};
    display(arr, 8);
    count_sort(arr, 8);
    printf("after sorting..... \n");
    display(arr, 8);
}
