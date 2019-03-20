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
    int minPathSum(vector<vector<int>> &grid)
    {
        size_t m = grid.size(), n = grid[0].size();
        for (size_t j = 1; j < n; ++j)
            grid[0][j] += grid[0][j - 1];
        for (size_t i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];
        for (size_t i = 1; i < m; ++i)
        {
            for (size_t j = 1; j < n; ++j)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
        return grid[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    println(s.minPathSum(grid));
    return 0;
}
