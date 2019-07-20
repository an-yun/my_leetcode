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
        while(pre->left || pre->right){
            cur = pre;
            //for current layer
            Node *pre_connect = nullptr;
            while (cur)
            {
                if(cur->left)
                {
                    if(pre_connect)
                        pre_connect->next = cur->left;
                    if(cur->right)
                    {
                        static_cast<Node *>(cur->left)->next = cur->right;
                        pre_connect = static_cast<Node *>(cur->right);
                    }
                    else
                        pre_connect = static_cast<Node *>(cur->left);
                }
                else if(cur->right)
                {
                    if(pre_connect)
                        pre_connect->next = cur->right;
                    pre_connect = static_cast<Node *>(cur->right);
                }
                cur = static_cast<Node *>(cur->next);
            }
            pre = pre->left?static_cast<Node *>(pre->left):static_cast<Node *>(pre->right);
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
