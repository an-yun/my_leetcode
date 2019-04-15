#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        size_t m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> health = dungeon;
        int upper_health =1+ ( health[0][0] < 0 ? -health[0][0] : 0);
        for (size_t j = 1; j < n; ++j)
        {
            health[0][j] += health[0][j - 1];
            upper_health = max(1-health[0][j], upper_health);
        }

        for (size_t i = 1; i < m; ++i)
        {
            health[i][0] += health[i - 1][0];
            upper_health = max(1-health[i][0], upper_health);
        }

        for (size_t i = 1; i < m; ++i)
        {
            for (size_t j = 1; j < n; ++j)
            {
                health[i][j] += max(health[i - 1][j], health[i][j - 1]);
                upper_health = max(1-health[i][j], upper_health);
            }
        }
        //binary search
        int l = 1, r = upper_health;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if ((health[0][0] = dungeon[0][0] + mid) <= 0)
            {
                l = mid + 1;
                continue;
            }

            for (size_t j = 1; j < n; ++j)
                health[0][j] = health[0][j - 1] <=0? -1:health[0][j - 1] + dungeon[0][j];

            for (size_t i = 1; i < m; ++i)
                health[i][0] = health[i - 1][0]<=0? -1:health[i - 1][0]+ dungeon[i][0];

            for (size_t i = 1; i < m; ++i)
                for (size_t j = 1; j < n; ++j)
                {
                    health[i][j] = dungeon[i][j];
                    if (health[i - 1][j] <= 0)
                    {
                        if (health[i][j - 1] <= 0)
                            health[i][j] = -1;
                        else
                            health[i][j] += health[i][j - 1];
                    }
                    else if (health[i][j - 1] <= 0)
                        health[i][j] += health[i - 1][j];
                    else
                        health[i][j] += max(health[i][j - 1], health[i - 1][j]);
                }

            // traceback
            if (health[m-1][n-1] <= 0)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
    int calculateMinimumHP1(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        // hp[i][j] represents the min hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> dungeon{
        
{-2,-3,3},{-5,-10,1},{10,30,-5}
        };
    println(s.calculateMinimumHP(dungeon));
    return 0;
}
