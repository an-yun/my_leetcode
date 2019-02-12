#include "zuo/ioutils.hpp"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
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
