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
        vector<map<size_t, bool>> cache(s_size + 1);
        cache[s_size][p_size] = true;
        return isMatch(0, 0, cache);
    }
};

int main()
{
    Solution s;
    println(s.isMatch("adceb", "*a*b"));
}
