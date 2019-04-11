#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        if(a.size() < b.size()) swap(a,b);
        size_t i =0, m = a.size(), n = b.size();
        string result(m+1,' ');
        for(;i<n;++i)
        {
            int value = a[m-i-1]+b[n-i-1]-2*'0'+carry;
            if(value > 1)
            {
                value %= 2;
                carry = true;
            }
            else carry = false;
            result[m-i] = '0'+value;
        }
        for(;i<m;++i)
        {
            int value = a[m-i-1]-'0'+carry;
            if(value > 1)
            {
                value = 0;
                carry = true;
            }
            else carry = false;
            result[m-i] = '0'+value;
        }
        if(carry)
        {
            result[0] ='1';
            return result;
        }
        else 
            return string(++result.begin(),result.end());
    }
};

int main()
{
    Solution s;
    string a("1010"), b("10");
    println(s.addBinary(a,b));
    return 0;
}
