#ifndef TREENODE_HPP
#define TREENODE_HPP

#include "zuo/ioutils.hpp"
#include <algorithm>
#include <limits>
#include <list>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int null = std::numeric_limits<int>::max();

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void free_tree(TreeNode *root)
{
    if(root)
    {
        free_tree(root->left);
        free_tree(root->right);
        delete root;
    }
}

TreeNode *make_tree(std::initializer_list<int> nums)
{
    if (nums.size() == 0)
        return nullptr;
    std::queue<TreeNode *> tree_q;
    auto root = new TreeNode(*nums.begin());
    tree_q.push(root);
    TreeNode *add_right(nullptr);
    for (auto b = nums.begin() + 1, e = nums.end(); b != e; ++b)
    {
        TreeNode *node(nullptr);
        if (*b != null)
        {
            node = new TreeNode(*b);
            tree_q.push(node);
        }
        if (add_right)
        {
            add_right->right = node;
            add_right = nullptr;
        }
        else
        {
            add_right = tree_q.front();
            add_right->left = node;
            tree_q.pop();
        }
    }
    return root;
}

struct PrintUnit
{
    size_t left_blank;
    size_t right_blank;
    size_t height;
    PrintUnit *left;
    PrintUnit *right;
    std::string str;
    PrintUnit():left_blank(0),right_blank(0),height(0),left(nullptr),right(nullptr),str(){};
};

void free_print_tree(PrintUnit *root)
{
    if(root)
    {
        free_print_tree(root->left);
        free_print_tree(root->right);
        delete root;
    }
}

PrintUnit *build_print_tree(TreeNode *root)
{
    PrintUnit *print_unit(nullptr);
    if (root)
    {
        print_unit = new PrintUnit();
        PrintUnit &current_print = *print_unit;
        current_print.str = std::to_string(root->val);
        if (root->left)
            current_print.left = build_print_tree(root->left);
        if (root->right)
            current_print.right = build_print_tree(root->right);
    }
    return print_unit;
}

void compute_print_info(PrintUnit *root_print, std::list<std::list<PrintUnit *>> &layer_q)
{
    if (root_print)
    {
        std::list<PrintUnit *> print_q{root_print};
        //分层
        while (!print_q.empty())
        {
            layer_q.push_front(print_q);
            PrintUnit *layer_end = print_q.back();
            PrintUnit *print_unit;
            do
            {
                print_unit = print_q.front();
                //下一层入队列
                auto l = print_unit->left;
                auto r = print_unit->right;
                if (l)
                    print_q.push_back(l);
                if (r)
                    print_q.push_back(r);
                print_q.pop_front();
            } while (print_unit != layer_end);
        }
        print_q = layer_q.front();
        layer_q.pop_front();
        for (auto &layer : layer_q)
        {
            //计算当前层连接线高度
            size_t layer_height=1;
            for (auto p : layer)
            {
                auto l = p->left;
                auto r = p->right;
                if(l)
                    layer_height = std::max(layer_height, l->right_blank);
                if(r)
                    layer_height = std::max(layer_height, r->left_blank);
            }
            //更新当前层打印信息
            for (auto p : layer)
            {
                p->height = layer_height;
                auto l = p->left;
                auto r = p->right;
                if(l)
                    p->left_blank = l->left_blank + l->str.size() + layer_height;
                if (r)
                    p->right_blank = layer_height + r->str.size() + r->right_blank;
            }
        }
        layer_q.push_front(print_q);
    }
}

void print_sub_tree(std::list<std::list<PrintUnit *>> &layer_q)
{
    auto &root_print = *layer_q.back().front();
    size_t len = root_print.left_blank + root_print.str.size() + root_print.right_blank;
    std::string empty_line(len, ' ');
    for (auto b = layer_q.rbegin(), e = layer_q.rend(); b != e;b++)
    {
        auto line = empty_line;
        auto branch_line = empty_line;
        auto height = b->front()->height;
        for (auto print_unit : *b)
        {
            auto &str = print_unit->str;
            std::copy(str.begin(), str.end(), line.begin() + print_unit->left_blank);
            //处理下一层
            auto l = print_unit->left;
            auto r = print_unit->right;
            if (l)
            {
                l->left_blank = print_unit->left_blank - height - l->str.size();
                branch_line[print_unit->left_blank - 1] = '/';
            }
            if (r)
            {
                r->left_blank = print_unit->left_blank + print_unit->str.size() + height;
                branch_line[print_unit->left_blank + str.size()] = '\\';
            }
        }
        //打印当前层
        println(line);
        //打印连接线
        for (size_t i = 0; i < height; ++i)
        {
            println(branch_line);
            for (size_t j = 0; j < len; ++j)
            {
                if (branch_line[j] == '/')
                    std::swap(branch_line[j], branch_line[j - 1]);
                else if (branch_line[j] == '\\')
                {
                    ++j;
                    std::swap(branch_line[j - 1], branch_line[j]);
                }
            }
        }
    }
}

void print_tree(TreeNode *root)
{
    if (root)
    {
        PrintUnit *root_print = build_print_tree(root);
        std::list<std::list<PrintUnit *>> layer_q;
        compute_print_info(root_print,layer_q);
        print_sub_tree(layer_q);
        free_print_tree(root_print);
    }
}

// 打印ListNode类型
inline void print(TreeNode *root)
{
    print_tree(root);
}
inline void println(TreeNode *root)
{
    print_tree(root);
    println();
}

#endif