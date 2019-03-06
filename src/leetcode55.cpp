#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int max_jump = 0, len = nums.size();
        for (int i = 0; i < len;i++)
        {
            max_jump = max(max_jump, i + nums[i]);
            if(max_jump >= len -1)
                return true;
            else if (max_jump == i)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> nums{3,2,1,0,4};
    Solution s;
    println(s.canJump(nums));
    return 0;
}
