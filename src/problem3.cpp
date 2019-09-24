#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<int, int> nums;
    for (int p = 0; p < t; ++p)
    {
        nums.clear();
        int sum = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            sum += num;
            ++nums[num];
        }
        int l_sum = 0, i = 0;
        for (auto &e : nums)
        {
            if (i < t / 2 && i + e.second >= t / 2)
            {
                l_sum += e.first * (t / 2 - i - 1);
                break;
            }
            l_sum += e.first * e.second;
            i += e.second;
        }
        cout << l_sum << " " << sum - l_sum << endl;
    }

    return 0;
}