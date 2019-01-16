#include "zuo/ioutils.hpp"
#include <algorithm>
#include <list>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(num1 == "0" || num2 == "0" )
            return "0";
        auto s1 = num1.size(), s2 = num2.size();
        string result(s1+s2,'0');
        int value = 0, carry = 0;
        for(size_t i=0;i<s1;i++)
        {
            value=0, carry=0;
            for(size_t j=0;j<s2;j++)
            {
                value = (num1[i]-'0') * (num2[j]-'0') + carry + result[i+j]-'0';
                carry = value / 10;
                value %= 10;
                result[i+j] = value + '0';
            }
            result[i+s2] += carry;
        }
        if(result.back() == '0') 
            result = result.substr(0, result.find_last_not_of('0') + 1);
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
    Solution s;
    println(s.multiply("123","456"));
}
