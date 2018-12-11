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
#include <string>
#include <vector>

namespace zuo
{
/*
* for public typedef
*/
typedef std::string string;
typedef unsigned index_t;
typedef boost::rational<unsigned long> unsigned_rational;

class rational
{
};

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

class Edge
{
  private:
};
} // namespace zuo
