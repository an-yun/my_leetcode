#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int solution_count = 0;
        int start_x = 0, start_y = 0, total_length = 2;
        //find start and count path length
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                }
                else if (grid[i][j] == 0)
                    total_length++;
            }
        }
        // depth first search
        int x = start_x, y = start_y, length_count = 1;
        //3 4 5 6 indicate direction 7 backtrace
        grid[x][y] = 3;
        while (true)
        {
            int &position_info = grid[x][y];
            int pre = position_info / 8, next = position_info % 8;
            int next_x = x, next_y = y;
            switch (next++)
            {
            case 3: //right
                next_y++;
                break;
            case 4: //down
                next_x++;
                break;
            case 5: //left
                next_y--;
                break;
            case 6: // up
                next_x--;
                break;
            case 7: //backtrace
                if (x == start_x && y == start_y)
                {
                    grid[x][y] = 1;
                    // start postion backtrace is end
                    return solution_count;
                }

                position_info = 0; //backtrace
                length_count--;
                switch (pre)
                {
                case 3:
                    --y;
                    break;
                case 4:
                    --x;
                    break;
                case 5:
                    ++y;
                    break;
                case 6:
                    ++x;
                    break;
                default:
                    break;
                }
                continue;
            default:
                break;
            }
            position_info = pre * 8 + next;
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
            {
                int &next_info = grid[next_x][next_y];
                if (next_info == -1 || next_info > 2)
                    continue;
                else if (next_info == 2) //end position
                {
                    if (length_count + 1 == total_length) //find a path
                        solution_count++;
                }
                else // visit the node
                {
                    length_count++;
                    x = next_x;
                    y = next_y;
                    grid[x][y] = (next - 1) * 8 + 3;
                }
            }
        }
        return solution_count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid{
        {0, 0, 0, 0, 0},
        {0, 2, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    println(s.uniquePathsIII(grid));
    return 0;
}
