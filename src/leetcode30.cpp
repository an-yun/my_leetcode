#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        return {};
    }
};

int main()
{
    Solution s;
    string str = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    print_vector(s.findSubstring(str, words));
    return 0;
}
