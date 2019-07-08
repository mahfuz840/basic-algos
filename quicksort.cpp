#include<stdio.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void my_swap(int* a, int* b);

int main()
{
    int arr[] = {3, 2, 8, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);

    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            printf("swapping i = %d j = %d low=%d high=%d\n",i,j,low,high);

            my_swap(&arr[i], &arr[j]);
        }
    }

    my_swap(&arr[i+1], &arr[high]);

    return (i+1);
}

void my_swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
