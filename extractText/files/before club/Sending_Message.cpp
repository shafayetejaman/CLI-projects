#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pii> vp;
typedef vector<string> vs;

int n;
string s1, s2;

bool fun(int i, string s)
{
    if (i == n) return s2 == s;

    return fun(i + 1, s + s1[i]) or fun(i + 1, s);
}

int main()
{
    while (!cin.eof())
    {
        cin >> s1 >> s2;
        n = s1.size();

        if (fun(0, "")) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }

    return 0;
}