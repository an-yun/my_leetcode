#include "zuo/ioutils.hpp"
#include <vector>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> row;
        for (int i = 0; i <= numRows;++i)
        {
            row.push_back(1);
            int pre = 1,temp;
            for (int j = 1; j < i; ++j)
            {
                temp = row[j];
                row[j] += pre;
                pre = temp;
            }
        }
        return row;
    }
};

int main()
{
    Solution s;
    println(s.getRow(3));
    return 0;
}
