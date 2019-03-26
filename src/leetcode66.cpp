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
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        auto b = digits.rbegin(), e = digits.rend();
        while(carry != 0 && b != e)
        {
            *b += carry;
            carry = *b / 10;
            *b %= 10;
            ++b;
        }
        if(carry != 0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> digits{9,9};
    println(s.plusOne(digits));
    return 0;
}
