#include "zuo/ioutils.hpp"
#include "zuo/maxflow.hpp"
#include <iostream>
#include <memory>

using namespace std;

void double_2_rational_test()
{
    vector<double> test_nums =
        {0.12, 1.5, 0.003, -0.125, 0, 1.23, -1.246};
    for (auto num : test_nums)
    {
        auto r = zuo::double2ratonal(num);
        cout << num << " -> " << r << ", ";
        if (std::abs(boost::rational_cast<double>(r) - num) > zuo::EPSILON)
            cout << "test failed for :" << num << "->" << r;
        cout << endl;
    }
}

void test_memory()
{
    vector<int> a{1, 2, 3}, b{4, 5, 6};
    println("a:", a);
    println("b:", b);
    allocator<vector<int>> alloc;
    auto p = alloc.allocate(2);
    uninitialized_fill_n(p, 1, a);
    uninitialized_fill_n(p + 1, 1, b);
    a[0] = 0;
    b[0] = -1;
    println("a:", a);
    println("b:", b);
    println("p[0]:", p[0]);
    println("p[1]:", p[1]);
    alloc.deallocate(p, 2);
}

int main()
{
    test_memory();
    //double_2_rational_test();
    return 0;
}
