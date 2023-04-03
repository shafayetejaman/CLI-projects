#include <bits/stdc++.h>

using namespace std;

// void pattern(int r, int c, int n)
// {
//     if (r > n)
//         return;
//     if (c < n)
//     {
//         cout << "# ";
//         pattern(r, c + 1, n);
//     }
//     else
//     {
//         cout << endl;
//         pattern(r + 1, r + 1, n);
//     }
// }

void bubble_sort(vector<int> &arr, int i, int j)
{
    int n = arr.size();
    if (i > n - 2)
        return;
    if (j < n - i - 1)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
        cout << j << " ";
        bubble_sort(arr, i, j + 1);
    }
    else
    {
        cout << endl;
        bubble_sort(arr, i + 1, 0);
    }
}

void selection_sort(vector<int> &arr, int i, int j, int min)
{
    int n = arr.size();
    if (i == n)
        return;

    if (j < n)
    {
        if (arr[min] > arr[j])
        {
            min = j;
        }
        selection_sort(arr, i, j + 1, min);
    }
    else
    {
        swap(arr[i], arr[min]);
        selection_sort(arr, i + 1, i + 2, i + 1);
    }
}

int main()
{
    vector<int> arr = {1, 5, 6, 7, 2, 3, 4};
    bubble_sort(arr, 0, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
