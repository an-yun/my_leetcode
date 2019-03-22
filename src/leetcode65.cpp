#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool isNumber(string s)
    {
        int state = 0;
        for(auto ch:s)
        {
            switch (state)
            {
                case 0:
                    if(ch == ' ') continue;
                    else if(ch == '+' || ch == '-') state = 1;
                    else if(ch >= '0' && ch <= '9') state = 2;
                    else if(ch == '.') state = 4;
                    else state = 9;
                    break;
                case 1:
                    if(ch == '.') state = 4;
                    else if(ch >= '0' && ch <= '9') state = 2;
                    else state = 9;
                    break;
                case 2:
                    if(ch == '.') state = 3;
                    else if(ch >= '0' && ch <= '9') continue;
                    else if(ch == 'e')state = 5;
                    else if(ch == ' ')state = 8;
                    else state = 9;
                    break;
                case 3:
                    if(ch >= '0' && ch <= '9') continue;
                    else if(ch == 'e')state = 5;
                    else if(ch == ' ')state = 8;
                    else state = 9;
                    break;
                case 4:
                    if(ch >= '0' && ch <= '9') state = 3;
                    else state = 9;
                    break;
                case 5:
                    if(ch == '+' || ch == '-') state = 6;
                    else if(ch >= '0' && ch <= '9') state = 7;
                    else state = 9;
                    break;
                case 6:
                    if(ch >= '0' && ch <= '9') state = 7;
                    else state = 9;
                    break;
                case 7:
                    if(ch == ' ')state = 8;
                    else if(ch >= '0' && ch <= '9') continue;
                    else state = 9;
                    break;
                case 8:
                    if(ch == ' ')continue;
                    else state = 9;
                    break;
                default:
                    return false;
                    break;
            }
        }
        switch (state)
        {

            case 2:
            case 3:
            case 7:
            case 8:
                return true;   
            default:
                return false;
            }
    }
};

int main()
{
    Solution s;
    println(s.isNumber("1 4"));
    return 0;
}
