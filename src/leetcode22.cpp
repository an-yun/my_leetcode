#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return vector<string>();
        if(n == 1) return {"()"};
        if(n == 2) return {"()()","(())"};
        vector<string> strings;
        collect("(", 1, 0, n, strings);
        return strings;

    }
    void collect(string str, int left, int right, int n, vector<string> &strings)
    {
        if(left >= n) 
        {
            str.append(n-right, ')');
            strings.push_back(str);
            return;
        }
        if (left <= right) collect(str+'(', left+1, right, n, strings);
        else
        {
            collect(str+'(', left+1, right, n, strings);
            collect(str+')', left, right+1, n, strings);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto parenthesis = s.generateParenthesis(4);
    for (auto &p: parenthesis)
        cout<<p<<"\n";
    return 0;
}