#include "my_hederfile.h"

using namespace std;



int main()
{
    vector<int> vector = {1,2,3};
    int array[] = {1, 2, 3};
    int n = 3;

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    vector.push_back(4);
    cout << endl;
    print(vector);
    

    return 0;
}