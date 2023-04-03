#include <bits/stdc++.h>

using namespace std;

int partition(int *arr, int l, int r)
{
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < arr[r])
        {
            i++;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[i + 1], arr[r]);
    return i+1;
}

void quicksort(int *arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, r);
    }
}

int main(void)
{
    int arr[] = {9, 6, 3, 2, 7};

    quicksort(arr, 0, 4);
    for (auto i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}