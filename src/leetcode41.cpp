#include <algorithm>
#include <vector>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int nums_size = nums.size();
        if(nums_size == 0) return 1;
        for(int i=0; i<nums_size; i++)
        {
            auto &num = nums[i];
            while(num <= nums_size && num >= 1 && nums[num-1] != num)
                swap(num, nums[num-1]);
        }
        int min_missing = 0;
        for(auto num:nums)
            if(num != ++min_missing) return min_missing;
        return ++min_missing;
    }

};

int main()
{
    Solution s;
    vector<int> nums{3,4,-1,1,0,2};
    println(s.firstMissingPositive(nums));
}
