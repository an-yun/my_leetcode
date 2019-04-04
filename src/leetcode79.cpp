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
    bool dfs(vector<vector<char>> &board, string &word, size_t start, int x, int y, int m, int n)
    {
        if (start >= word.size()) // match case
            return true;
        if (x < 0 || x >= m || y < 0 || y >= n) // edge case
            return false;
        char temp = board[x][y];        // for save memory
        if (word[start] != board[x][y]) // for match char
            return false;
        else
            board[x][y] = '\0';// Using board  can save memory here
        bool match_word = dfs(board, word, start + 1, x - 1, y, m, n) || dfs(board, word, start + 1, x + 1, y, m, n) ||
                          dfs(board, word, start + 1, x, y - 1, m, n) || dfs(board, word, start + 1, x, y + 1, m, n);
        board[x][y] = temp;// restore board[x][y]
        return match_word;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.size() == 0)
            return true;
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        if (n == 0)
            return false;
        // dfs search
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, 0, i, j, m, n)) //try every position
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
    println(s.exist(board, "ABCB"));
    return 0;
}
