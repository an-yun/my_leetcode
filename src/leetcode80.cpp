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
    int removeDuplicates(vector<int>& nums) {
        size_t n = nums.size();
        if(n < 3)
            return n;
        bool repeat = nums[1] == nums[0];
        int length = 2;
        for (size_t i = 2; i < n;++i)
        {
            if(nums[i] == nums[length-1])
            {
                if(!repeat)
                {
                    repeat = true;
                    swap(nums[i], nums[length++]);
                }
            }
            else 
            {

                repeat = false;
                swap(nums[i], nums[length++]);
            }
        }
        return length;
    }
};


int main()
{
    Solution s;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    println(s.removeDuplicates(nums));
    println(nums);
    return 0;
}
