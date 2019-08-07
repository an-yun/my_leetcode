#include "zuo/ioutils.hpp"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int sell = prices.back(), profit = 0;
        // for (auto b = ++prices.rbegin(), e = prices.rend(); b != e;++b)
        // {
        //     if(*b >= sell)
        //         sell = *b;
        //     else
        //         profit = max(profit, sell - *b);

        // }
        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices{7, 1, 5, 3, 6, 4};
    println(s.maxProfit(prices));
    return 0;
}
