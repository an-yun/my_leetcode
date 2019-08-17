#include "zuo/ioutils.hpp"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int buy = prices.front(), profit = 0;
        for (auto b = ++prices.begin(), e = prices.end(); b != e;++b)
        {
            if(*b > buy)
                profit += *b - buy;
            buy = *b;    

        }
        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices{1,2,3,4,5};
    println(s.maxProfit(prices));
    return 0;
}
