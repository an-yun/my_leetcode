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
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        else if( n == 1) return {0,1};
        else
        {
            auto gray_pre = grayCode(n-1);
            const int h = 1 << (n-1);
            gray_pre.resize(h *2);
            for(int i=0;i<h;++i)
                gray_pre[h+i] = gray_pre[h-1-i]+h;
            return gray_pre;
        }
    }
};

int main()
{
    Solution s;
    println(s.grayCode(3));
    return 0;
}
