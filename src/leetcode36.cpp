#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include "zuo/ioutils.hpp"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool repeat_flag[9];
        // check row
        for(int i=0;i<9;i++)
        {
            fill(repeat_flag, repeat_flag+9,false);
            for(auto c:board[i])
            {
                if(c == '.') continue;
                if( repeat_flag[c-'1'])
                    return false;
                repeat_flag[c-'1']=true;
            }
        }
        // check column
        for(int j=0;j<9;j++)
        {
            fill(repeat_flag, repeat_flag+9,false);
            for(int i=0;i<9;i++)
            {
                auto c = board[i][j];
                if(c == '.') continue;
                if( repeat_flag[c-'1'])
                    return false;
                repeat_flag[c-'1'] = true;
            }
        }
                
        return true;
    }
};
int main()
{
    
    return 0;
}
