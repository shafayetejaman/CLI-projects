#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &arr)
{
    for (auto i = 0; i < arr.size() - 1; i++)
    {
        for (auto j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
                break;
        }
    }
}

int main()
{
    vector<int> arr = {6, 3, 2, 1};

    insertion_sort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    



    return 0;
}