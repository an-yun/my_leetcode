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
        int size = s.size();
        if(size == 0) return 1;
        switch(s[0])
        {
            case '0':
                return 0;
            case '1':
                return numDecodings(s.substr(1)) + (size > 1? numDecodings(s.substr(2)):0);
            case '2':
                if(s[1] <= '6') return numDecodings(s.substr(1)) + (size > 1? numDecodings(s.substr(2)):0);
            default:
                return numDecodings(s.substr(1));
        }
    }
};

int main()
{
    Solution s;
    println(s.numDecodings("162"));
    return 0;
}
