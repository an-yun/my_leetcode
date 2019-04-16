#include "zuo/ioutils.hpp"
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include "boost/countertree/cntree_map.hpp"

using namespace std;

class Solution {
public:
    string encode(const string &str)
    {
        vector<int> code_num(26, 0);
        for(auto ch:str)
            code_num[ch - 'a']++;
        string code;
        for(auto count: code_num)
            code.append(to_string(count)+'#');
        return code;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> code_map;
        for (auto &str:strs)
        {
            string code = encode(str);
            code_map[code].push_back(str);
        }
        for (auto &pair:code_map)
            result.push_back(pair.second);
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs{
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    println(s.groupAnagrams(strs));
    return 0;
}
