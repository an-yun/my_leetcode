#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

ostream &operator<<(ostream &out, const Interval &internal)
{
    out << "[" << internal.start << ", " << internal.end << "]";
    return out;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
  public:
    static bool compare_interval(const Interval &t1, const Interval &t2)
    {
        return t1.start < t2.start;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        auto b = intervals.begin(), e = intervals.end();
        auto next_inter = lower_bound(b, e, newInterval, compare_interval);
        auto less_end = next_inter;
        if (next_inter != b)
        {
            auto pre_inter = next_inter - 1;
            if (newInterval.start <= pre_inter->end)
            {
                newInterval.start = pre_inter->start;
                newInterval.end = max(newInterval.end, pre_inter->end);
                less_end = pre_inter;
            }
        }
        while (next_inter != e && next_inter->start <= newInterval.end)
        {
            newInterval.end = max(newInterval.end, next_inter->end);
            next_inter++;
        }
        vector<Interval> result(b, less_end);
        result.push_back(newInterval);
        result.insert(result.end(), next_inter, e);
        return result;
    }
};

int main()
{
    vector<Interval> intervals{{1, 5}};
    Solution s;
    println(s.insert(intervals, {2,3}));
    return 0;
}
