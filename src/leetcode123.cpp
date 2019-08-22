#include "zuo/ioutils.hpp"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = numeric_limits<int>::min(), hold2 =hold1;
        int release1 = 0, release2 = 0;
        for(auto p:prices)
        {
            release2 = max(release2, hold2 + p);
            hold2 = max(hold2, release1 - p);
            release1 = max(release1, hold1 + p);
            hold1 = max(hold1, -p);
        }
        return release2;
    }
};

int main()
{
    Solution s;
    vector<int> prices{1,2,3,4,5};
    println(s.maxProfit(prices));
    return 0;
}
