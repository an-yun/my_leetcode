#include "zuo/ioutils.hpp"
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  private:
    string str;
    string pattern;
    size_t s_size;
    size_t p_size;
    bool isMatch(size_t s_i, size_t p_i, vector<map<size_t, bool>> &cache)
    {
        if (s_i > s_size || p_i > p_size)
            return false;
        if (s_i < s_size && p_i == p_size)
            return false;
        auto &s_cache = cache[s_i];
        if (s_cache.find(p_i) != s_cache.end())
            return s_cache[p_i];
        auto c = pattern[p_i];
        bool result = false;
        switch (c)
        {
        case '?':
            if (s_i == s_size)
                result = false;
            else
                result = isMatch(s_i + 1, p_i + 1, cache);
            break;
        case '*':
            for (size_t i = s_i; i <= s_size; i++)
            {
                if (isMatch(i, p_i + 1, cache))
                {
                    result = true;
                    break;
                }
            }
            break;
        default:
            result = str[s_i] == c && isMatch(s_i + 1, p_i + 1, cache);
            break;
        }
        return s_cache[p_i] = result;
    }

  public:
    bool isMatch(string s, string p)
    {
        if (s == p)
            return true;
        s_size = s.size();
        p_size = p.size();
        if (s_size > 0 && p_size == 0)
            return false;
        str = s;
        pattern = p;
        // vector<map<size_t, bool>> cache(s_size + 1);
        // cache[s_size][p_size] = true;
        // return isMatch(0, 0, cache);
        return isMatch();
    }
    bool isMatch()
    {
        vector<vector<bool>> match_table(s_size + 2, vector<bool>(p_size + 2, false));
        match_table[s_size][p_size] = true;
        vector<bool> true_indices(p_size + 1, false);
        true_indices[p_size] = true;
        for (int i = s_size; i >= 0; i--)
        {
            for (int j = p_size - 1; j >= 0;j--)
            {
                auto c = pattern[j];
                if(c == '?')
                    match_table[i][j] = match_table[i + 1][j + 1];
                else if (c == '*')
                    match_table[i][j] = true_indices[j + 1];
                else
                    match_table[i][j] = i < s_size && c == str[i] && match_table[i + 1][j + 1];
                if(match_table[i][j])
                    true_indices[j] = true;
            }
        }
        return match_table[0][0];
    }
};

int main()
{
    Solution s;
    println(s.isMatch("cb", "?b"));
}
