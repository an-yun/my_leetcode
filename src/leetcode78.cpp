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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all_subsets((1<<nums.size()),vector<int>());
        int current_size = 1;
        for (auto num : nums)
        {
            for (int i = 0; i < current_size;++i)
            {
                all_subsets[current_size + i] = all_subsets[i];
                all_subsets[current_size + i].push_back(num);
            }
            current_size *= 2;
        }

        return all_subsets;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,2,3};
    println(s.subsets(nums));
    return 0;
}
