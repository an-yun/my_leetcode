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
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool last_line_zeros = false;
        for (int j = 0; j < n; ++j)
        {
            if (matrix[m - 1][j] == 0)
            {
                last_line_zeros = true;
                break;
            }
        }
        if (last_line_zeros)
        {
            for (int j = 0; j < n; ++j)
                matrix[m - 1][j] = matrix[m - 1][j] == 0;
        }
        bool pre_zeros = false;
        for (int i = 0; i < m; ++i)
        {
            bool current_zeros = false;
            for (int j = 0; j < n; ++j)
            {
                if (pre_zeros)
                    matrix[i - 1][j] = 0;
                if (i < m - 1)
                {
                    if (matrix[i][j] == 0)
                    {
                        matrix[m - 1][j] = last_line_zeros;
                        current_zeros = true;
                    }
                    else if (matrix[m - 1][j] == last_line_zeros)
                        matrix[i][j] = 0;
                }
            }
            pre_zeros = current_zeros;
        }
        for (int j = 0; j < n; ++j)
        {
            if (matrix[m - 1][j] == last_line_zeros)
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{
        {0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}};
    s.setZeroes(matrix);
    println(matrix);
    return 0;
}
