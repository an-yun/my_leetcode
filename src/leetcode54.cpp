#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  private:
    int m, n;

  public:
    void collect(int start, vector<vector<int>> &matrix, vector<int> &result)
    {
        int right = n - start, bottom = m - start, index = m * n - (right - start) * (bottom - start);
        for (int j = start; j < right; j++)
            result[index++] = matrix[start][j];
        if (index == m * n)
            return;
        for (int i = start + 1; i < bottom; i++)
            result[index++] = matrix[i][right - 1];
        if (index == m * n)
            return;
        for (int j = right - 2; j >= start; j--)
            result[index++] = matrix[bottom - 1][j];
        for (int i = bottom - 2; i > start; i--)
            result[index++] = matrix[i][start];
        if (index != m * n)
            collect(start + 1, matrix, result);
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        if(m==0)
            return {};
        n = matrix[0].size();
        if(n == 0)
            return {};
        vector<int> result(m * n, 0);
        collect(0, matrix, result);
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix =
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}};
    vector<vector<int>> matrix1 =
        {
            {7},
            {9},
            {6}};
    Solution s;
    println(s.spiralOrder(matrix));
    println(s.spiralOrder(matrix1));
    return 0;
}
