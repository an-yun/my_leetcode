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
    static int factorial(int i) 
    {
        static int fact[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        return fact[i];
    }

  public:
    string getPermutation1(int n, int k)
    {
        //time comlexity n!
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

    string getPermutation(int n, int k)
    {
        //time comlexity n^2
        string result(n, '1');
        iota(result.begin(), result.end(), '1');
        if(k==1)
            return result;
        if (k == factorial(n))
        {
            reverse(result.begin(), result.end());
            return result;
        }
        for (int i = 0, left = n - 1; i < n;i++, left--)
        {
            int current_num = (k - 1) / factorial(left), current_index =current_num+i;
            swap(result[i], result[current_index]);
            while(current_index > i+1 && result[current_index] < result[current_index-1])
            {
                swap(result[current_index], result[current_index-1]);
                current_index--;
            }
            while(current_index < n-1 && result[current_index] > result[current_index+1])
            {
                swap(result[current_index], result[current_index+1]);
                current_index++;
            }
            k -= current_num * factorial(left);
        }
        return result;
    }
};

int main()
{
    Solution s;
    println(s.getPermutation(4, 6));
    return 0;
}
