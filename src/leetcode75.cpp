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
    void sortColors(vector<int>& nums) {
        for (auto l = nums.begin(), g = l, b = l, e = nums.end(); b != e;++b)
        {
            switch (*b)
            {
                case 0:
                    swap(*b, *g);
                    swap(*l++, *g++);
                    break;
                case 1:
                    swap(*b, *g++);
                    break;
                default:
                    break;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{2,0,2,1,1,0};
    s.sortColors(nums);
    println(nums);
    return 0;
}
