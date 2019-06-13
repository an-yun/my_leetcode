#include <string>
#include <vector>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        size_t m = s.size(), n = t.size();
        if(m < n)
            return 0;
        vector<unsigned> row(n + 1, 0);
        row[n] = 1;
        for (int i = m - 1; i >= 0; --i)
        {
            unsigned pre = row[n],tmp;
            for (int j = n - 1; j >= 0; --j)
            {
                tmp = row[j];
                if (s[i] == t[j])
                    row[j] += pre;
                pre = tmp;
            }
        }
        return row[0];
    }
};

int main()
{
    Solution s;
    println(s.numDistinct("a", ""));
    return 0;
}