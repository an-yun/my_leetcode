/*
 * This file is for test rational class
 *
 * author: zuo
 * date  : 2018年 12月 11日 星期二 22:46:43 CST
 */
#include "boost/rational.hpp"
#include "zuo/rational.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using b_rational = boost::rational<int>;
using z_rational = zuo::rational;
using std::vector;

int main()
{
    // test for boost ration
    vector<b_rational> brs{{4, 1}, {24, 36}, {24, 52}};
    for (auto &r : brs)
        std::cout << r << " ";
    std::cout << std::endl;
    std::cout <<brs[1]<<"-"<<brs[0]<<"="<< brs[1]-brs[0]<< std::endl;
    vector<z_rational>zrs{{4, 1}, {24, 36}, {24, 52},{0.168},{-0.3214},{138, -51}};
    for (auto &r : zrs)
        std::cout << r << " ";
    std::cout << std::endl;

    std::cout <<zrs[1]<<"-"<<zrs[0]<<"="<< zrs[1]-zrs[0]<< std::endl;
    return 0;
}
