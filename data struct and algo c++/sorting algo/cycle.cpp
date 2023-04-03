#include "my_hederfile.cpp"

using namespace std;

int cycle_sort(vector<int> &arr)
{
    for (auto i = 0; i < arr.size(); i++)
    {
        int corr = arr[i];
        if (corr < arr.size() and arr[corr] != arr[i])
        {
            swap(arr[i], arr[corr]);
            i--;
        }
    }
    for (auto i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i)
        {
            return i;
        }
    }
    return arr.size();
}

int main()
{
    vector<int> v = {2, 4, 1, 3, 5};
    vector<int> v2 = {12, 13, 14};

    // print(v);
    // cout << cycle_sort(v);
    // v.insert(v.begin() + 3, v2.begin(), v2.end());
    // print(v);
 
    return 0;
}
