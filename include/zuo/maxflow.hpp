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
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace zuo
{
/*
* for public typedef
*/
typedef std::string string;
typedef unsigned index_t;

class Node
{
  public:
    /*
      * public api
      */
    Node(string name = "", index_t index = 0);
    string name() const;
    index_t index() const;

  private:
    string m_name;
    index_t m_index;
};

const double EPSILON = 1e-9;
using boost_rational = boost::rational<long long>;

boost_rational double2ratonal(double num)
{
    long long i = 1;
    while (std::abs(num - static_cast<long long>(num)) > EPSILON)
    {
      if (std::abs(num) > LONG_LONG_MAX / 10 || i > LONG_LONG_MAX / 10)
      {
        std::cerr << "convert " << num << " to rational faled: it's too long. Now set it 0." << std::endl;
        return {};
      }
      else
      {
        i *= 10;
        num *= 10;
      }
    }
    return {static_cast<long long>(num), i};
}

double rational2double(const boost_rational &r)
{
    return 1.0* r.numerator() / r.denominator();
}

class Edge
{
  private:
};
} // namespace zuo
