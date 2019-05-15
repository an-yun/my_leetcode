#include "zuo/ioutils.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <list>
#include <limits>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t m = s1.size(), n = s2.size(), l = s3.size();
        if(m+n != l)
            return false;
        if(l == 0)
            return true;
        else if (m == 0)
            return s2 == s3;
        else if (n == 0)
            return s1 == s3;

        vector<bool> is_inter(m+1,true);
        for (size_t j = 1; j <= m; ++j)
                is_inter[j] = (is_inter[j - 1] && s1[j - 1] == s3[j - 1]);
        for (size_t i = 1; i <= n; ++i)
        {
            is_inter[0] = is_inter[0] && s2[i - 1] == s3[i - 1];
            for (size_t j = 1; j <= m; ++j)
                is_inter[j] = (is_inter[j] && s2[i - 1 ] == s3[i + j - 1] ) || (is_inter[j - 1] && s1[j - 1] == s3[i + j - 1]);
        }
        return is_inter.back();
    }
};

int main()
{
    Solution s;
    println(s.isInterleave("aacaac","aacaaeaac","aacaaeaaeaacaac"));
    return 0;
}
