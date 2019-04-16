#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        while (m > 0 && n > 0)
        {
            if(nums1[m-1] > nums2[n-1])
            {
                nums1[m + n - 1] = nums1[m - 1];
                --m;
            }
            else 
            {
                nums1[m + n - 1] = nums2[n-1];
                --n;
            }
        }
        copy(nums2.begin(), nums2.begin() + n, nums1.begin());
    }
};

int main()
{
    Solution s;
    vector<int> num1{1, 2, 3, 0, 0, 0, 0, 0, 0}, num2{-3,-1,2, 5, 6};
    s.merge(num1,3,num2,5);
    println(num1);
    return 0;
}
