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
        list<Node *> node_q{root};
        auto layer_end = root;
        while(!node_q.empty())
        {
            auto node = node_q.front();
            node_q.pop_front();
            if(node->left)
                node_q.push_back(static_cast<Node *>(node->left));
            if(node->right)
                node_q.push_back(static_cast<Node *>(node->right));
            if(node != layer_end)
                node->next = node_q.front();
            else
            {
                if(!node_q.empty())
                    layer_end = node_q.back();
                node->next = nullptr;
            }

        }
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
