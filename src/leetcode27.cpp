#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        auto size = nums.size();
        if (size == 0)
            return 0;
        unsigned end = 0;
        for (unsigned i = 0; i < size; i++)
        {
            if (nums[i] != val)
            {
                swap(nums[i], nums[end]);
                end++;
            }
        }
        return end;
    }
};

int test_solution(vector<int> &array, int val)
{
    Solution s;
    auto k = s.removeElement(array, val);
    for (int i = 0; i < k; i++)
        cout << array[i] << " ";
    cout << endl;
    return k;
}

int main(int argc, char const *argv[])
{
    vector<int> l{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    cout << test_solution(l, val) << endl;
    return 0;
}
