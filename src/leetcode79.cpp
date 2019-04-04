#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool dfs(vector<vector<char>> &board, string &word, size_t start, int x, int y,int m, int n,vector<vector<bool>> &visited)
    {
        if (start >= word.size()) // match case
            return true;
        if (x < 0 || x >= m || y < 0 || y >= n )// edge case
            return false;
        if(visited[x][y] || word[start] != board[x][y])// for match case
            return false;
        else
            visited[x][y] = true; // Using board  can save memory here, for example char temp = borad[x][y];borad[x][y] = '\0';
        if (dfs(board, word, start + 1, x - 1, y, m, n, visited) || dfs(board, word, start + 1, x + 1, y, m, n, visited) || dfs(board, word, start + 1, x, y - 1, m, n, visited) || dfs(board, word, start + 1, x, y + 1, m, n, visited))
            return true; //  Corresponding to line 25 ,add one line above :borad[x][y] = temp;
        else
        {
            visited[x][y] = false;
            return false;
        }
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.size() == 0)
            return true;
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        if(n == 0)
            return false;
        // dfs search 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, 0, i, j, m, n, visited)) //try every position
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    println(s.exist(board, "ABCCED"));
    return 0;
}
