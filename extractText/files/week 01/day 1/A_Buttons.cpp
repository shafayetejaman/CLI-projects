// https://atcoder.jp/contests/abc124/tasks/abc124_a?lang=en

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;
#define endl '\n'
#define ll long long
#define range(n) for(auto j = 0; j < n; j++)

const int N = 1e5 + 1;

int main()
{
    int x, y, sum = 0;
    cin >> x >> y;

    range(2)
    {
        if (x > y) sum += x--;
        else sum += y--;
    }

    cout << sum;


    return 0;
}