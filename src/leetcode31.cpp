#include <algorithm>
#include <iostream>
#include <vector>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 从最后一位开始修改
        next_permutation(nums.begin(), nums.end());
    }
};


int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 3, 1};
    print_vector(nums);
    s.nextPermutation(nums);
    cout << "Next permutation:" << endl;
    print_vector(nums);
    return 0;
}
