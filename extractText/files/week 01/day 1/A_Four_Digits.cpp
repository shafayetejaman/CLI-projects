// https://atcoder.jp/contests/abc222/tasks/abc222_a?lang=en

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
    string s;
    cin >> s;

    loop(4 - s.size()) cout << 0;
    cout << s;

    return 0;
}