#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
class Solution
{
  private:
    void next(string &str)
    {
        auto e = str.end(),border = e-2;
        while(*border >= *(border+1))
            border--;
        auto first_lager = lower_bound(border+1, e,*border ,greater<int>())-1;
        swap(*border, *first_lager);
        reverse(border + 1, e);
    }

  public:
    string getPermutation(int n, int k)
    {
        string result(n, '1');
        iota(result.begin(), result.end(), '1');
        if(k==1)
            return result;
        if (k == static_cast<int>(tgamma(n + 1)))
        {
            reverse(result.begin(), result.end());
            return result;
        }
        for (int i = 1; i < k; i++)
            next(result);
        return result;
    }
};

int main()
{
    Solution s;
    println(s.getPermutation(4, 9));
    return 0;
}
