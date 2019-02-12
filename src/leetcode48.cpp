#include "zuo/ioutils.hpp"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        size_t n = matrix.size();
        for (size_t i = 0; i < n;i++)
            for (size_t j = 0; j < i;j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    s.rotate(matrix);
    println(matrix);
    return 0;
}
