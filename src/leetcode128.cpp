#include "zuo/ioutils.hpp"
#include "zuo/treenode.hpp"
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> num_length;
        int max_length = 0;
        for(auto num:nums)
        {
            if(num_length[num])
                continue;
            int length = num_length[num-1] + num_length[num+1] + 1;
            max_length = max(max_length,length);
            num_length[num] = num_length[num-num_length[num-1]] = num_length[num+num_length[num+1]] = length;
        }
        return max_length;
    }
};

int main()
{
    Solution s;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    println(s.longestConsecutive(nums));
    return 0;
}
