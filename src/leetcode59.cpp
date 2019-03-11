#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Solution
{
  private:
    int n;
    void fill(int start, int value, vector<vector<int>> &matrix)
    {
        int end = n - start;
        if (end <= start)
            return;
        for (int j = start; j < end; j++)
            matrix[start][j] = value++;
        if (end > start + 1)
        {
            for (int i = start + 1; i < end; i++)
                matrix[i][end-1] = value++;
            for (int j = end - 2;j > start; j--)
                matrix[end - 1][j] = value++;
            for (int i = end - 1; i > start;i--)
                matrix[i][start] = value++;
            fill(start + 1, value, matrix);
        }
    }

  public:
    vector<vector<int>> generateMatrix(int n)
    {
        this->n = n;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        fill(0, 1, matrix);
        return matrix;
    }
};

int main()
{
    Solution s;
    println(s.generateMatrix(4));
    return 0;
}
