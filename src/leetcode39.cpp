#include "zuo/ioutils.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        map<int, vector<vector<int>>> c;
        /*
        * The recurrence is 
        * C[i][t] = \cup_{k=0}^{t/n_i} \{s\cup \{n_i\}*k |s\in C[i-1][t-k*n_i]\}
        * 
        * where C[i][t] is the set consisting of numbers from 1st to i-th, the sum of which is t. $\{n_i\}*k$ means a set with k n_i, for example $\{3\}*2$ means $\{3,3\}$.
         */
        for (auto num : candidates)
        {
            auto pre_c = c;
            for (int k = 1; k <= target / num; k++)
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
    vector<int> nums{2, 3, 5};
    int target = 8;
    Solution s;
    println(s.combinationSum(nums, target));
    return 0;
}
