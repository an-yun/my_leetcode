#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], current_max = max_sum;
        size_t len = nums.size();
        for(size_t i=1; i < len;i++)
        {
            current_max = max(nums[i], current_max + nums[i]);
            max_sum = max(max_sum, current_max);
        }
        return max_sum;
    }

};

int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    println(s.maxSubArray(nums));
    return 0;
}
