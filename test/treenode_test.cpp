#include "zuo/treenode.hpp"

int main()
{
    auto tree = make_tree({1, 21, 2, null, 3, 4, 5, 6,null,7,null,null,null,8});
    println(tree);
    return 0;
}