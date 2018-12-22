#include "zuo/ioutils.hpp"
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() != 0)
        {
            int start = 0, end = nums.size() - 1;

            while (end >= start)
            {
                if (nums[start] == target && nums[end] == target)
                    return {start, end};
                int mid = (start + end) / 2;
                if (target > nums[mid])
                    start = mid + 1;
                else if (target == nums[mid])
                {
                    int s_mid = mid;
                    while (target == nums[s_mid] && s_mid > start)
                        s_mid = (start + s_mid) / 2;
                    if (target != nums[s_mid])
                        start = s_mid + 1;
                    int e_mid = mid;
                    while (target == nums[e_mid] && e_mid < end - 1)
                        e_mid = (e_mid + end) / 2;
                    if (target != nums[e_mid])
                        end = e_mid - 1;
                    else if (target != nums[end])
                        end = e_mid;
                }
                else
                    end = mid - 1;
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10,11,12,15,17,17,17};
    println(s.searchRange(nums, 17));
    return 0;
}
