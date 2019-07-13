#include "zuo/treenode.hpp"
#include <algorithm>
#include <list>

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
    Node* connect(Node* root) {
        return root;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree<Node>({1,2,3,4,5,6,7});
    println(s.connect(tree));
    free_tree(tree);
    return 0;
}
