#include "zuo/ioutils.hpp"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution
{
  private:
    bool valid(vector<vector<char>> &board, int i, int j, char value)
    {
        // check row
        for (int k = 0; k < 9; ++k)
        {
            if (board[k][j] == value)
                return false;
        }
        // check column
        for (int k = 0; k < 9; ++k)
        {
            if (board[i][k] == value)
                return false;
        }
        //check box
        int box_x = i / 3, box_y = j / 3;
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                if (board[box_x * 3 + x][box_y * 3 + y] == value)
                    return false;
            }
        }
        return true;
    }

  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        list<int> empty_postions;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    empty_postions.push_back(i * 9 + j);
            }
        }
        auto current_position = empty_postions.begin();
        while (current_position != empty_postions.end())
        {
            int i = (*current_position) / 9, j = (*current_position) % 9;
            char c = board[i][j], value;
            if (c == '.')
                value = '1';
            else
                value = c + 1;
            while (value <= '9' && !valid(board, i, j, value))
                value++;
            if (value > '9')
            {
                board[i][j] = '.';
                current_position--;
            }
            else
            {
                board[i][j] = value;
                current_position++;
            }
        }
    }
};
int main()
{
    vector<vector<char>> board =
        {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
    Solution s;
    s.solveSudoku(board);
    println(board);
    return 0;
}
