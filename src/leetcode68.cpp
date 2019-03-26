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
    string padding(vector<string> &words, size_t words_length, size_t b, size_t e, size_t maxWidth)
    {
        size_t size = e - b;
        string line(maxWidth, ' ');
        if (size == 1)
            copy(words[b].begin(), words[b].end(), line.begin());
        else
        {
            size_t step = (maxWidth - words_length) / (size - 1), res = (maxWidth - words_length) % (size - 1), p = words[b].size() + step;
            copy(words[b].begin(), words[b].end(), line.begin());
            if (res > 0)
            {
                ++p;
                --res;
            }
            while (++b != e)
            {
                copy(words[b].begin(), words[b].end(), line.begin() + p);
                p += step + words[b].size();
                if (res > 0)
                {
                    ++p;
                    --res;
                }
            }
        }
        return line;
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        size_t len = words.size(), pre = 0, current_len = words[0].size();
        vector<string> result;
        for (size_t i = 1; i < len; ++i)
        {
            if (current_len + words[i].size() + 1 > static_cast<size_t>(maxWidth))
            {
                result.push_back(padding(words, current_len + 1 - (i - pre), pre, i, maxWidth));
                pre = i;
                current_len = words[i].size();
            }
            else
                current_len += words[i].size() + 1;
        }
        string line(maxWidth, ' ');
        current_len = 0;
        while (pre != len)
        {
            copy(words[pre].begin(), words[pre].end(), line.begin() + current_len);
            current_len += words[pre].size() + 1;
            ++pre;
        }
        result.push_back(line);
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    println(s.fullJustify(words, 20));
    return 0;
}
