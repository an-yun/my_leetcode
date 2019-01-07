#include "zuo/ioutils.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string countAndSay(int n)
    {
        // it's boring
        switch (n)
        {
            case 0:
                return "";
            case 1:
                return "1";
            case 2:
                return "11";
            case 3:
                return "21";
            case 4:
                return "1211";
            case 5:
                return "111221";
            default:
                string pre = countAndSay(n - 1), result;
                int pre_size = pre.size(),count =1;
                for (int i = 1; i < pre_size;i++)
                {
                    if(pre[i] == pre[i-1])
                        count++;
                    else
                    {
                        result.append(to_string(count) + pre[i - 1]);
                        count = 1;
                    }
                }
                result.append(to_string(count) + pre.back());
                return result;
            }
    }
};

int main()
{
    Solution s;
    println(s.countAndSay(6));
    return 0;
}
