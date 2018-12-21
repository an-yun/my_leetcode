#include "zuo/ioutils.hpp"
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        return binary_search(nums, target, 0, nums.size());
    }

    int binary_search(vector<int> &nums, int target, size_t s, size_t e)
    {
        while (s < e)
        {
            size_t mid = (s + e) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[s] > nums[mid])
            {
                if (target > nums[mid] && target < nums[s])
                    s = mid + 1;
                else   e = mid;
            }
            else
            {
                if (target < nums[mid] && target >= nums[s])
                    e = mid;
                else   s = mid+1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 5, 7, 0, 1, 2};
    for(auto target:nums)
        println(s.search(nums, target));
    println(s.search(nums, 6));
    return 0;
}
