#include "zuo/ioutils.hpp"
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        auto len = nums.size();
        if(len < 2) return {nums};
        vector<vector<int>> results;
        auto current_permutation = nums;
        results.push_back(current_permutation);
        auto b = current_permutation.begin(), e = current_permutation.end();
        for(next_permutation(b,e); current_permutation != nums ; next_permutation(b,e))
            results.push_back(current_permutation);
        return results;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,1,2};
    println(s.permuteUnique(nums));
    return 0;
}
