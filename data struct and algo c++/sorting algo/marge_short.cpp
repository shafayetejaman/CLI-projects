#include <iostream>
#include <vector>

using namespace std;

void marge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void marge_short(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        marge_short(arr, start, mid);
        marge_short(arr, mid + 1, end);
        marge(arr, start, mid, end);
    }
}

int main(void)
{
    vector<int> arr = {8, 5, 6, 2, 1, 4, 7, 10, 3, 9};

    marge_short(arr, 0, arr.size() - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}