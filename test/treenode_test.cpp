#include "zuo/treenode.hpp"

int main()
{
    auto tree = make_tree({1,null,2,3});
    println(tree);
    free_tree(tree);
    return 0;
}