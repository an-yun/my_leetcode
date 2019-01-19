#include "zuo/ioutils.hpp"
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int jump1(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 2)
            return 0;
        int min_jump = 0, pre_max = 1, current_max=1;
        for (int i = 1; i <= len; i++)
        {
            if (i > pre_max)
            {
                min_jump++;
                pre_max = current_max;
            }
            current_max = max(current_max, i + nums[i - 1]);
        }
        return min_jump;
    }
    int jump(vector<int> &nums)
    {
        return jump1(nums);
        int len = nums.size();
        if (len < 2)
            return 0;
        //breadth first search
        vector<int> dis(len, -1);
        list<int> visit_queue;
        dis[0] = 0;
        visit_queue.push_back(0);
        while (dis[len - 1] == -1)
        {
            auto node = visit_queue.front();
            visit_queue.pop_front();
            auto num = nums[node];
            for (int j = 1; j <= num && j + node < len; j++)
            {
                auto next_node = j + node;
                if (dis[next_node] == -1)
                {
                    visit_queue.push_back(next_node);
                    dis[next_node] = dis[node] + 1;
                }
            }
        }
        return dis[len - 1];
    }
};

int main()
{
    Solution s;
    vector<int> nums{2, 3, 1, 1, 4};
    println(s.jump(nums));
    return 0;
}
