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
    int numDecodings(string s) {
        int len = s.size();
        if(len == 0) return 1;
        int cur = s[--len]!='0', last = 1,temp;
        while(--len >= 0)
        {
            temp = cur;
            switch(s[len])
            {
                case '0':
                    cur = 0;
                    break;
                case '1':
                    cur += last;
                    break;
                case '2':
                    if( s[len+1] < '7') cur += last;
                    break;
                default:
                    break;

            }
            last = temp;
        }
        return cur;
    }
};

int main()
{
    Solution s;
    println(s.numDecodings("226"));
    return 0;
}
