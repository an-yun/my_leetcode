#include "zuo/ioutils.hpp"
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        auto len = nums.size();
        if(len < 2) return {nums};
        vector<int> sub_nums(len-1);
        iota(sub_nums.begin(), sub_nums.end(),1);
        auto pre_permutaions = permute(sub_nums);
        size_t pre_size = pre_permutaions.size(), total_size = pre_size * len;
        vector<vector<int>> results(total_size, nums);
        for(size_t i = 0;i < len; i++)
        {
            for(size_t j = 0;j < pre_size; j++)
            {
                auto &permutation = results[i*pre_size + j], &pre_permutaion = pre_permutaions[j];
                int num = permutation[i];
                for(size_t k = i;k > 0 ;k--) permutation[k] = permutation[k-1];
                nums = permutation;
                for(size_t k = 1;k < len;k++) permutation[k] = nums[pre_permutaion[k-1]];
                permutation[0] = num;
            } 
            
        }
        return results;
    }
};

int main()
{
    Solution s;
    vector<int> nums{4,1,2,3,5};
    println(s.permute(nums));
    return 0;
}
