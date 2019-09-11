#include "zuo/ioutils.hpp"
#include "zuo/treenode.hpp"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        return {};
    }
};

int main()
{
    Solution s;
    vector<string> word_list{"hot","dot","dog","lot","log","cog"};
    println(s.findLadders("hit", "cog" ,word_list));
    return 0;
}
