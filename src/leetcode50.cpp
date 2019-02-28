#include "zuo/ioutils.hpp"
#include <algorithm>
#include <string>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        if (n == -1) return 1/x;
        if (n == 0) return 1;
        if (n == 1) return x;
        double half = myPow(x,n/2);
        if(n % 2)
            if( n < 0 ) return half * half / x;
            else return half * half * x;
        else return half * half;
    }
};

int main()
{
    Solution s;
    println(s.myPow(5, 3));
    return 0;
}