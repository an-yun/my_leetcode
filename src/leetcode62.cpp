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
    int uniquePaths1(int m, int n)
    {
        if (m <= 1 || n <= 1)
            return 1;
        vector<vector<int>> table(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n;j++)
                table[i][j] = table[i - 1][j] + table[i][j - 1];
        return table[m - 1][n - 1];
    }
    int uniquePaths(int m, int n)
    {
        // less memory
        if (m <= 1 || n <= 1)
            return 1;
        vector<int> table(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                table[j] += table[j-1];
        return table[n - 1];
    }
};

int main()
{
    Solution s;
    println(s.uniquePaths(51, 9));
    return 0;
}
