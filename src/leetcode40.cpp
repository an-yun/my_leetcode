#include "zuo/ioutils.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        map<int,int> count;
        for(auto num:candidates) count[num]++;
        map<int, vector<vector<int>>> c;
        /*
        * The recurrence is 
        * C[i][t] = \cup_{k=0}^{count_i} \{s\cup \{n_i\}*k |s\in C[i-1][t-k*n_i]\}
        * 
        * where C[i][t] is the set consisting of numbers from 1st to i-th, the sum of which is t. $\{n_i\}*k$ means a set with k n_i, for example $\{3\}*2$ means $\{3,3\}$.
         */
        for (auto num_count_pair : count)
        {
            int num = num_count_pair.first;
            auto pre_c = c;
            auto num_count = count[num];
            for (int k = 1; k <= num_count; k++)
            {
                c[k * num].push_back(vector<int>(k, num));
                for (auto &k_v : pre_c)
                {
                    int sum = k_v.first + num * k;
                    if (sum <= target)
                    {
                        auto pre_combinations = k_v.second, &combinations = c[sum];
                        for (auto &pre_combination : pre_combinations)
                        {

                            pre_combination.insert(pre_combination.end(), k, num);
                            combinations.insert(combinations.end(), pre_combination);
                        }
                    }
                }
            }
        }
        return c[target];
    }
};

int main()
{
    vector<int> nums{2,5,2,1,2};
    int target = 5;
    Solution s;
    println(s.combinationSum2(nums, target));
    return 0;
}
