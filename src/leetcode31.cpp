#include <algorithm>
#include <iostream>
#include <vector>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

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