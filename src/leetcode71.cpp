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

class Solution
{
  public:
    string simplifyPath(string path)
    {
        list<string> dir_stack, dirs;
        size_t start = 0, p;

        while ((p = path.find_first_of('/', start)) != string::npos)
        {
            if(p != start)dirs.push_back(path.substr(start, p - start));
            start = p + 1;
        }
        dirs.push_back(path.substr(start));
        for (auto &dir : dirs)
        {
            if (dir.size() == 0)
                continue;
            else if (dir[0] == '.')
            {
                auto s = dir.size();
                switch (s)
                {
                    case 1:
                        continue;
                        break;
                    case 2:
                        if(dir[1] == '.')
                        {    if (!dir_stack.empty())dir_stack.pop_back();
                        }
                        else
                            dir_stack.push_back(dir);
                        break;
                    default:
                        dir_stack.push_back(dir);
                        break;
                }
            }
            else  dir_stack.push_back(dir);
        }
        string result = "";
        for(auto &dir:dir_stack)
        {
            result += '/' + dir;
        }
        return result.size()?result:"/";
    }
};

int main()
{
    Solution s;
    println(s.simplifyPath("/a//b////c/d//././/.."));
    return 0;
}
