#include <bits/stdc++.h>

using namespace std;


int main()
{
    int y;
    cin >> y;

    long long nodes = pow(2, y-1);
    long long val = 1;

    for (int i = 3; i <= y; i++)
    {
        val *= 2;
    }

    cout << val * nodes << endl;

    return 0;
}