#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void print_arr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void selection_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = a[i];
        int x = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                x = j;
            }
        }
        if (x != i)
        {
            int temp = a[i];
            a[i] = a[x];
            a[x] = temp;
        }
    }
}

void merge(int *A, int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
int main(void)
{

    int a[] = {9, 8, 7,6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    // bubble_sort(a, n);
    // print_arr(a, n);
    // printf("\n");

    // selection_sort(a, n);
    // print_arr(a, n);
    // printf("\n");

    mergeSort(a, 0, n - 1);
    print_arr(a, n);
    printf("\n");
    return 0;
}