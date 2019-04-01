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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0)
        {
            if(target < matrix[i][j] )
                --j;
            else if (target == matrix[i][j])
                return true;
            else
                ++i;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{
        {1}
    };
    println(s.searchMatrix(matrix, 13));
    return 0;
}
