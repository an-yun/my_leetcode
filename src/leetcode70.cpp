#include "zuo/ioutils.hpp"
#include <algorithm>

class Solution
{
    public:
        int climbStairs(int n)
        {
            int pre=1, cur=1, temp;
            while(--n > 0)
            {
                temp = cur;
                cur += pre;
                pre = temp;
            }
            return cur;
        }
};

int main()
{
    Solution s;
    println(s.climbStairs(5));
    return 0;
}
