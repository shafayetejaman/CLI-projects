#include "my_hederfile.h"

using namespace std;

void per(string arr, string ans)
{
    if (arr.empty())
    {
        print(ans);
        return;
    }

    char c = arr[0];

    for (auto i = 0; i <= ans.size(); i++)
    {
        string f = ans.substr(0, i);
        string l = ans.substr(i);
        per(arr.substr(1), f + c + l);
    }
}

int main()
{
    {
        vector<string> v = dial(res, a + code[i], phone);
        insert(ans.end(), v.begin(), v.end());

        per("abc", "");
        return 0;











      }  }