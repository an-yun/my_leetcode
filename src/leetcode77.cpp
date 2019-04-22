#include "zuo/ioutils.hpp"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k <= 0 || k > n) return {{}};
        vector<vector<vector<int>>> cache(k,vector<vector<int>>());
        vector<vector<int>> first(n-k+1, {1});
        for(int i=1;i<= n-k+1;++i)first[i-1][0] = i;
        cache[0] = first;
        vector<vector<int>> pre;
        for(int i = n - k +2; i <= n ;++i)
        {
            pre.clear();
            for(int j = 0; j<= i - n + k -1;++j)
            {
                auto current = pre;
                for(auto &com:current) com.push_back(i);
                pre = cache[j];
                cache[j].insert(cache[j].end(), current.begin(), current.end());
            }
        }
        return cache[k-1];
    }
};

int main()
{
    Solution s;
    println(s.combine(4,2));
    return 0;
}
