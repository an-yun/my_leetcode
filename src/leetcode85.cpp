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
    int largestRectangleArea(vector<int> heights)
    {
        int heights_size = heights.size();
        if (heights_size == 0)
            return 0;
        int max_area = heights[0];
        list<int> h_stack{0};
        for (int i = 1; i < heights_size; ++i)
        {
            int top = h_stack.back(), current_top = top;
            if (heights[i] == heights[current_top])
                continue;
            int last_i = i;
            while (!h_stack.empty() && heights[i] < heights[current_top = h_stack.back()])
            {
                max_area = max(max_area, heights[current_top] * (i - current_top));
                last_i = current_top;
                h_stack.pop_back();
            }
            h_stack.push_back(last_i);
            heights[last_i] = heights[i];
        }
        while (!h_stack.empty())
        {
            int current_top = h_stack.back();
            max_area = max(max_area, heights[current_top] * (heights_size - current_top));
            h_stack.pop_back();
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        size_t m = matrix.size();
        if (m == 0)
            return 0;
        size_t n = matrix[0].size();
        if (n == 0)
            return 0;
        vector<int> row_heights(n, 0);
        int result = 0;
        // tranform to largestRectangleArea problem
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                    row_heights[j] ++;
                else
                    row_heights[j] = 0;
            }
            // solve largestRectangleArea problem for echo row
            result = max(result, largestRectangleArea(row_heights));
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}},
        matrix1{
            {'1', '1', '0'},
            {'1', '1', '1'},
            {'0', '1', '0'}};
    println(s.maximalRectangle(matrix1));
    return 0;
}
