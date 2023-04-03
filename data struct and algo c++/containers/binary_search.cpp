#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<int> &arr, int tar)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == tar)
            return mid;


        if (arr[mid] < tar)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }
    return -1;
}

int LinearSearch(const vector<int> &arr, int tar)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == tar)
            return i;
    }
    return -1;
}

int main(void)
{
    vector<int> arr = {1, 2, 4, 5, 6, 9, 12, 23, 44};
    int tar = 23;

    cout << BinarySearch(arr, tar) << endl;
    cout << LinearSearch(arr, tar) << endl;

    cout << distance(arr.begin(), lower_bound(arr.begin(), arr.end(), tar)) << endl;

    return 0;
}