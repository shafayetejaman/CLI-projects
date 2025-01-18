// https://atcoder.jp/contests/abc193/tasks/abc193_a?lang=en

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
#define loop(n) for(auto j = 0; j < n; j++)

//const int N = 1e5 + 1;

int main()
{
    double a, b;
    cin >> a >> b;

    string s = to_string(((a - b) / a) * 100);

    cout << s;


    return 0;
}