#include "zuo/ioutils.hpp"
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto s = triangle.size();
        if(s == 0)
            return 0;
        for (auto i = s; i > 1; --i)
        {
            for (auto j = 0; j + 1u < i; ++j)
                triangle[i - 2][j] += min(triangle[i - 1][j], triangle[i - 1][j + 1]);
        }
        return triangle[0][0];
        
    }
};

int main()
{
    Solution s;
    vector<vector<int>> triangle{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    println(s.minimumTotal(triangle));
    return 0;
}
