/*
 * This file is for maxflow problem using Ford-Fulkerson algorithm, Edmonds-Karp algorithm, Dinic's algorithm, Dinic's algorithm with dynamic trees data structure, General push_relabel,  FIFO push_relabel and preflow_push.
 * Time complexity:
 *      Ford-Fulkerson algorithm : m |f_max|
 *      Edmonds-Karp algorithm : nm^2
 *      Dinic's algorithm : n^2m
 *      Dinic's algorithm with dynamic trees data structure : nm log n
 *      General push_relabel : n^2m
 *      FIFO push_relabel : n^3
 *      preflow_push algorithm : n^2m^{1/2}
 *for n nodes, m edges and f_max maxflow value
 *
 * author: zuo
 * date  : 2018年 12月 10日 星期一 22:06:42 CST
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
