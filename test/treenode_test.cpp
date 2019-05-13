#include "zuo/treenode.hpp"

int main()
{
    auto tree = make_tree({1,32,2,3,null,34,null,4,5,null,null,6,null,7,8,9,null,null,10});
    println(tree);
    free_tree(tree);
    return 0;
}