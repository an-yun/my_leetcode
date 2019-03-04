#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool inline check(const vector<int> &positions, int t)
    {
        int x = positions[t];
        for (int i = 0; i < t; i++)
        {
            if(positions[i] == x)
                return false;
            if(abs(x - positions[i]) == t - i)
                return false;
        }
        return true;
    }

    int totalNQueens(int n)
    {
        int solution_count = 0;    
        if (n == 0)     
            return solution_count;
        vector<int> positions(n);
        for (int t = 0; t >= 0;) // record recursion count
        {
            if( t == n) //find a solution
            {
                solution_count++;
                positions[--t]++;
            }
            int &x = positions[t];
            if(x == n ) // backtrace
            {
                if(t == 0)
                    break;
                x = 0;
                positions[--t]++;
            }
            else if(check(positions,t))
                t++;
            else
                x++;
        }
        return solution_count;
    }
};

int main()
{
    Solution s;
    println(s.totalNQueens(4));
    return 0;
}
