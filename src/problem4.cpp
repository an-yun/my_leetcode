#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    set<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        if(num)
            nums.insert(num);
    }
    int min_num = 0;
    for (int i = 0; i < k; ++i)
    {
        if(nums.empty())
            cout << 0 << endl;
        else
        {
            int top = *nums.begin();
            cout << top - min_num << endl;
            min_num = top;
            nums.erase(nums.begin());
        }
    }
    return 0;
}