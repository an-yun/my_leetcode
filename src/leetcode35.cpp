#include <iostream>
#include<vector> 
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0,end = nums.size();
        while(start < end)
        {
            int mid = (start + end) / 2;
            if(target < nums[mid])
                end = mid;
            else if (target == nums[mid])
                return mid;
            else start = mid + 1;
        }
        return start; 
    }
};


int main()
{
    Solution s;
    vector<int> nums{1,3,5,6};
    print(s.searchInsert(nums, 2));
    return 0;
}
