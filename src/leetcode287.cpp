#include "zuo/ioutils.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int left = 1, right = n + 1;
        int mid = (left + right) / 2;
        for (; mid > left; mid = (left + right) / 2)
        {
            int count_left = 0, count_mid = 0, right_count = 0;
            for (auto num : nums)
            {
                if (num >= left && num < right)
                {
                    if (num < mid)
                        ++count_left;
                    else if (num == mid)
                        ++count_mid;
                    else
                        ++right_count;
                }
            }
            if (count_mid > 1)
                return mid;
            if (count_left > mid - left)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 3, 4, 2, 2};
    println(s.findDuplicate(nums));
    return 0;
}
