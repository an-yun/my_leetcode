#include "zuo/ioutils.hpp"
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

ostream &operator<< (ostream & out, const Interval &internal)
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
    vector<Interval> merge(vector<Interval> &intervals)
    {
        size_t length = intervals.size();
        if (length < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare_interval);
        vector<Interval> merge_intervals{intervals[0]};
        for (size_t i = 1; i < length;i++)
        {
            auto &pre_back = merge_intervals.back(), current = intervals[i];
            if(current.start <= pre_back.end)
                pre_back.end = max(pre_back.end,current.end);
            else
                merge_intervals.push_back(current);
        }
        return merge_intervals;
    }
};

int main()
{
    vector<Interval> intervals{{1,3},{2,6},{8,10},{15,18},{18,19}};
    Solution s;
    println(s.merge(intervals));
    return 0;
}
