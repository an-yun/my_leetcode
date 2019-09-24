#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<int, int> nums;
    int m = 0;
    for (int i = 0; i < t; ++i)
    {
        int n, num;
        cin >> n >> num;
        m += n;
        nums[num] += n;
    }
    auto b = nums.begin();
    auto e = nums.rbegin();
    int max_time = 0, l = (*b).second, r = (*e).second;
    for (int i = 0; i * 2 < m; ++i)
    {
        if (i >= l)
        {
            ++b;
            l += (*b).second;
        }

        if (i >= r)
        {
            ++e;
            r += (*e).second;
        }

        max_time = max(max_time, (*b).first + (*e).first);
    }
    cout << max_time << endl;
    return 0;
}