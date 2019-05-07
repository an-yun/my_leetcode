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
    bool check(const string &str, int b, int e)
    {
        if(str[b] == '0' && e - b > 1) return false;
        unsigned num = 0;
        for(;b<e;++b)
            num = num *10 + str[b]-'0';
        return num < 256;
    }

    vector<string> restoreIpAddresses(string s) {
        size_t len = s.size();
        if(len < 4 || len > 12) return {};
        vector<string> result;
        size_t pos[4]{0,1,2,2};
        int t = 3;
        while(true)
        {
            switch(t)
            {
                case 0:
                    return result;
                case 1:
                case 2:
                case 3:
                    if(pos[t] < len + t -4 && pos[t] - pos[t-1] < 3 )
                    {
                        if(check(s,pos[t-1],++pos[t]))
                        {
                            if(t < 3)pos[t+1] = pos[t];
                            ++t;
                        }
                    }
                    else --t;
                    break;
                default:
                    if(check(s,pos[3],len))//find a valid ip
                    {
                        string ip;
                        for(int i=0;i<3;++i)
                        {
                            ip.append(s.substr(pos[i],pos[i+1]-pos[i]));
                            ip.append(".");
                        }
                        ip.append(s.substr(pos[3], len-pos[3]));
                        result.push_back(ip);
                    }
                    --t;

            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    println(s.restoreIpAddresses("2112135"));
    return 0;
}
