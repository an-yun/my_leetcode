#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <set>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        int m = s.size(), n = t.size();
        if(n == 0)
            return "";
        string result;
        int min_len = -1;
        map<char, int> right_pos;// maintain most right position for every char in t
        set<int> window_left;//maintian min window left
        for(auto ch:t) right_pos[ch] = -1;
        window_left.insert(-1);
        for(int i=0; i<m; ++i)
        {
            auto ch = s[i];
            auto pos_pair = right_pos.find(ch);
            if( pos_pair != right_pos.end() )
            { 
                int &pos = pos_pair->second;
                //remove pre window_left
                if(pos != -1 || static_cast<int>(window_left.size()) >= n)
                    window_left.erase(pos);
                //update right pos
                pos = i;
                //insert new window_left
                window_left.insert(pos);
                //compute the min window
                auto the_left = *window_left.begin();
                if(the_left >= 0)
                {
                    int new_len = i - the_left + 1;
                    if(min_len == -1 || new_len < min_len)
                    {
                        min_len = new_len;
                        result = s.substr(the_left, new_len);
                    }
                }
                
            }    
        }
        return result;
    }
};

int main()
{
    Solution s;
    println(s.minWindow("aa","aa"));
    return 0;
}
