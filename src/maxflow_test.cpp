#include "zuo/maxflow.hpp"
#include <iostream>

void double_2_rational_test()
{
    std::vector<double> test_nums =
        {0.12,1.5,0.003,-0.125,0,1.23,-1.246};
    for(auto num:test_nums)
    {
        auto r = zuo::double2ratonal(num);
        std::cout << num << "->" << r<<", ";
        if(std::abs(zuo::rational2double(r) - num)> zuo::EPSILON)
            std::cout << "test failed for :" << num << "->" << r ;
        std::cout << std::endl;
    }
}

int main()
{
    double_2_rational_test();
    return 0;
}

