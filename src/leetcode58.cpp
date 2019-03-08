#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t end = s.find_last_not_of(' '), start = s.find_last_of(' ', end);
        if(end == string::npos)
            return 0;
        if(start == string::npos)
            return end + 1;
        return end - start;
    }
};

int main()
{
    Solution s;
    println(s.lengthOfLastWord("a "));
    return 0;
}
