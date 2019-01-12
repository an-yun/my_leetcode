#include "zuo/ioutils.hpp"
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        size_t len = height.size();
        if (len <= 2)
            return 0;
        int water_trap = 0;
        list<size_t> bounder_indices;
        bounder_indices.push_back(0);
        for (size_t i = 1; i < len; i++)
        {
            auto pre_index = bounder_indices.back();
            if (height[i] < height[pre_index])
                bounder_indices.push_back(i);
            else if( height[i] == height[pre_index])
                bounder_indices.back() = i;
            else
            {
                bounder_indices.pop_back();
                size_t pre_new_index;
                while (!bounder_indices.empty() && height[i] >= height[pre_new_index = bounder_indices.back()])
                {
                    water_trap += (height[pre_new_index] - height[pre_index]) * (i - pre_new_index - 1);
                    pre_index = pre_new_index;
                    bounder_indices.pop_back();
                }
                if(!bounder_indices.empty())
                    water_trap += (height[i] - height[pre_index]) * (i - pre_new_index - 1);
                bounder_indices.push_back(i);
            }
        }
        return water_trap;
    }
};

int main()
{
    Solution s;
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    println(s.trap(height));
}
