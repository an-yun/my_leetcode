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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    println(s.maximalRectangle(matrix));
    return 0;
}
