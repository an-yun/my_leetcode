#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        // for special case
        if (dividend == divisor)
            return 1;
        if (dividend == 0 || divisor == INT32_MIN)
            return 0;
        if (divisor == 1)
            return dividend;
        
        if (dividend == INT32_MIN)
        {
            // handle for overflow 
            if (divisor == -1)
                return INT32_MAX;
            // transform divide range to [1,2^31-1]
            else if (divisor < 0)
                return 1 + divide(-(dividend - divisor), -divisor);
            else
                return -1 - divide(-(dividend + divisor), divisor);
        }
         // transform divide range to [1,2^31-1]
        if (dividend < 0)
            return -divide(-dividend, divisor);
        if (divisor < 0)
            return -divide(dividend, -divisor);
        // handle for dividend:[1,2^31-1] divide divisor:[1,2^31-1]
        if (divisor > dividend)
            return 0;
        int r_divisor = divisor, result = 0;
        while ((r_divisor << 1) > 0 && (r_divisor << 1) <= dividend)
            r_divisor <<= 1;
        while (r_divisor >= divisor)
        {
            result <<= 1;
            if (dividend >= r_divisor)
            {
                result += 1;
                dividend -= r_divisor;
            }
            r_divisor >>= 1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    int a = 1100540749, b = -1090366779;
    cout << s.divide(a, b) << endl;
    cout << a / b << endl;
    return 0;
}
