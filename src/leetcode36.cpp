#include <iostream>
#include <vector>
#include <queue>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
private:
    vector<vector<char>> m_board;
    
    bool check_board()
    {

        
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        m_board = board;    
        return check_board();        
    }
};
int main()
{
    
    return 0;
}
