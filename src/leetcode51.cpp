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

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;    
        if (n == 0)     
            return solutions;
        vector<string> board(n, string(n, '.'));
        vector<int> positions(n);
        for (int t = 0; t >= 0;) // record recursion count
        {
            if( t == n) //find a solution
            {
                solutions.push_back(board);
                auto &solution = solutions.back();
                for (int i = 0; i < n;i++)
                    solution[i][positions[i]] = 'Q';
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
        return solutions;
    }
};

int main()
{
    Solution s;
    println(s.solveNQueens(4));
    return 0;
}
