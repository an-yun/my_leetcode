#include <algorithm>
#include <iostream>
#include <vector>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //标准库  next_permutation(nums.begin(), nums.end());
        /*
         参考 http://􀋋sherlei.blogspot.com/2012/12/leetcode-next-permutation.html
         */
        // 特殊情况
        if(nums.size()<= 1)
            return;
        
        // 找到第一个降序的位置
        auto b = nums.rbegin();
        for (auto  e = nums.rend(); b+1 != e; b++)
            if(*(b+1) < *b )
                break;
        // 如果找到了
        if(++b != nums.rend())
        {
            auto l = upper_bound(nums.rbegin(), b,*b);
            swap(*b, *l);
            reverse(nums.rbegin(), b);
        }
        else
            reverse(nums.begin(),nums.end());
    }
};


int main()
{
    Solution s;
    vector<int> nums{1,1,5};
    print(nums);
    s.nextPermutation(nums);
    cout << "Next permutation:" << endl;
    print(nums);
    return 0;
}
