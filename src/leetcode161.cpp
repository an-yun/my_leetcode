#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        int m = s.size(), n = t.size();
        switch(abs(m-n))
        {
            case 0:
                {
                    bool have_replaced = false;
                    for(int i=0;i<m;++i)
                    {
                        if(s[i] != t[i])
                        {
                            if(have_replaced) return false;
                            else have_replaced = true;
                        }
                    }
                    return have_replaced;
                }
            case 1:
                {
                    bool s_less = m < n;
                    bool have_deleted = false;
                    for(int i=0,j=0;i<m;++i,++j)
                    {
                        if(s[i] != t[j])
                        {
                            if(have_deleted) return false;
                            else 
                            {
                                if(s_less)--i;
                                else --j;
                                have_deleted = true;
                            }
                        }
                    }
                    return have_deleted;
                }
            default:
                return false;
        }
        return false;
    }
};

int main()
{
    Solution s;
    println(s.isOneEditDistance("bcd","bcb"));
    return 0;
}
