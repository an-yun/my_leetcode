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
    bool search(vector<int> &nums, int target)
    {

        int start = 0, end = nums.size();
        if (end == 0)
            return false;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target || nums[start] == target || nums[end - 1] == target)
                return true;
            else
            {
                bool mid_pre_pivot = true;
                // judge pivot
                if (nums[start] == nums[end - 1])
                {
                    if (nums[mid] < nums[start])
                        mid_pre_pivot = false;
                    else if (nums[mid] == nums[start])
                    {
                        --end;
                        continue;
                    }
                }
                else
                    mid_pre_pivot = nums[mid] >= nums[start];

                if (target < nums[mid])
                {
                    if (mid_pre_pivot && target < nums[start])
                        start = mid + 1;
                    else
                        end = mid;
                }
                else
                {
                    if (!mid_pre_pivot && target > nums[end - 1])
                        end = mid;
                    else
                        start = mid + 1;
                }
            }
        }
        return start < nums.size() && nums[start] == target;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2,2,2,0,1};
    println(s.search(nums, 0));
    return 0;
}
