#include <bits/stdc++.h>


using namespace std;

void quick_sort(vector<int> &arr, int left, int right)
{
    if (left > right)
    {
        return;
    }
    int pivot = arr[left + (right-left)/ 2];
    int l = left;
    int r = right;
    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    quick_sort(arr, left, r);
    quick_sort(arr, l, right);
}

int main()
{
    vector<int> arr = {4, 3, 6, 7, 8, 2, 1};

    quick_sort(arr, 0, arr.size() - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
  

    return 0;
}
