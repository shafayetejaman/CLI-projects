#include "my_hederfile.h"

using namespace std;
class Solution
{
public:
    int minimumRecolors(string b, int k)
    {
        vector<int> v;
        int count = 0;
        int min_count = INT_MAX;

        for (auto i = 0; i <b.size(); i++)
        {

                if (b[i] == 'W')
                    count++;

                if (i % (k-1) == 0)
                {
                    count = 0;
                    min_count = min(min_count, count);
                }
        }
        return min_count;
    }
};

int main()
{


    return 0;
}