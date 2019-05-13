#include "zuo/treenode.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    vector<TreeNode *> generateUniqTrees(int n)
    {
        switch (n)
        {
        case 0:
            return {nullptr};
        case 1:
            return {new TreeNode(1)};
        default:
            vector<TreeNode *> all_trees;
            for (int i = 0; i < n; i++)
            {
                auto l_trees = generateUniqTrees(i);
                auto r_trees = generateUniqTrees(n - 1 - i);
                for (auto l : l_trees)
                {
                    for (auto r : r_trees)
                    {
                        auto root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        all_trees.push_back(root);
                    }
                }
            }
            return all_trees;
        }
    }

    void set_values(vector<TreeNode *> &trees)
    {
        for (auto tree : trees)
        {
            int value = 1;
            inorderTraversal(tree, value);
        }
    }

    void inorderTraversal(TreeNode *root, int &value)
    {
        if (root)
        {
            inorderTraversal(root->left, value);
            root->val = value++;
            inorderTraversal(root->right, value);
        }
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n <= 0)
            return {};
        auto all_trees = generateUniqTrees(n);
        set_values(all_trees);
        return all_trees;
    }
};

int main()
{
    Solution s;
    auto trees = s.generateTrees(4);
    println(trees);
    return 0;
}