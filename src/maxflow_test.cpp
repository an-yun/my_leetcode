#include "zuo/maxflow.hpp"
#include <iostream>

using namespace std;

void double_2_rational_test()
{
    vector<double> test_nums =
        {0.12,1.5,0.003,-0.125,0,1.23,-1.246};
    for(auto num:test_nums)
    {
        auto r = zuo::double2ratonal(num);
        cout << num << " -> " << r<<", ";
        if(std::abs(boost::rational_cast<double>(r) - num)> zuo::EPSILON)
            cout << "test failed for :" << num << "->" << r ;
        cout << endl;
    }
}

int main()
{
    double_2_rational_test();
    return 0;
}

