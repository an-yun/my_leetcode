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
        auto node = root;
        while(node)
        {
            Node temp_node(0, nullptr, nullptr, nullptr);
            auto current_node = &temp_node; //next layer head
            //for current layer
            while(node)
            {
                if(node->left)
                {
                    current_node->next = node->left;
                    current_node = static_cast<Node*>(current_node->next);
                }
                if(node->right)
                {
                    current_node->next = node->right;
                    current_node = static_cast<Node*>(current_node->next);
                }
                node = static_cast<Node *>(node->next);
            }
            node = static_cast<Node*> (temp_node.next);
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
