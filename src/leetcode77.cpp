#include "zuo/ioutils.hpp"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k <= 0 || k > n) return {{}};
        vector<vector<vector<int>>> cache(k,vector<vector<int>>());
        cache[0] = {{1}};
        vector<vector<int>> pre;
        for(int i = 2; i <= n ;++i)
        {
            int j = max(0, k+i-n-1);
            pre = j?cache[j-1]:vector<vector<int>>{{}};
            for(; j< k && j < i ;++j)
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
/* a better solution
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};
*/
int main()
{
    Solution s;
    println(s.combine(5,3));
    return 0;
}
