#include "zuo/ioutils.hpp"
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), l = s3.size();
        if(m+n != l)
            return false;
        if(l == 0)
            return true;
        vector<bool> is_inter(l, false);
        while(l--)
        {
            if(m && s1[--m])
            {
                
            }
        }
        return is_inter[0];
    }
};

int main()
{
    Solution s;
    println(s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    return 0;
}
