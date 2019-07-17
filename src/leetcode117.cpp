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
        if(!root)
            return root;
        Node* pre = root, *cur = nullptr;
        while(pre->left){
            cur = pre;
            //for current layer
            while(cur)
            {
                static_cast<Node *>(cur->left)->next = cur->right;
                if(cur->next)
                    static_cast<Node *>(cur->right)->next = static_cast<Node *>(cur->next)->left;
                cur = static_cast<Node *>(cur->next);
            }
            pre = static_cast<Node *>(pre->left);
        }

        return root;
    }
};

int main()
{
    Solution s;
    auto tree = make_tree<Node>({1,2,3,4,5,null,7});
    println(s.connect(tree));
    free_tree(tree);
    return 0;
}
