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
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> all_subsets((1 << nums.size()), vector<int>());
        int current_size = 1, *pre_num = nullptr, pre_size = 0;
        for (auto &num : nums)
        {
            if (pre_num && *pre_num == num)
            {
                for (int i = pre_size; i < current_size; ++i)
                {
                    all_subsets[current_size + i - pre_size] = all_subsets[i];
                    all_subsets[current_size + i - pre_size].push_back(num);
                }
                int temp_size = pre_size;
                pre_size = current_size;
                current_size += current_size - temp_size;
            }
            else
            {
                for (int i = 0; i < current_size; ++i)
                {
                    all_subsets[current_size + i] = all_subsets[i];
                    all_subsets[current_size + i].push_back(num);
                }
                pre_size = current_size;
                current_size *= 2;
            }
            pre_num = &num;
        }
        all_subsets.resize(current_size);
        return all_subsets;
    }
};

int main()
{
    Solution s;
    vector<int> nums{5,5,5};
    println(s.subsetsWithDup(nums));
    return 0;
}
