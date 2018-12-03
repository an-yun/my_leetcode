#include <algorithm>
#include <cstdio>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

struct Segment
{
    unsigned first;
    unsigned second;
    bool operator<(const Segment &s) const
    {
        return first < s.first && second < s.second;
    }
};
typedef vector<set<Segment>> SegmentsMap;

bool query_large_range(SegmentsMap &segment_sets, unsigned a, unsigned b, unsigned x, unsigned y);
bool query_small_range(SegmentsMap &segment_sets, unsigned a, unsigned b, unsigned x, unsigned y);

int main()
{

    unsigned n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    SegmentsMap segment_sets(n);

    // read segments
    unsigned l, r, p;
    for (unsigned i = 0; i < k; i++)
    {
        scanf("%d %d %d", &l, &r, &p);
        auto &set_p = segment_sets[p - 1];
        auto find = set_p.find({l, r});
        if (find != set_p.end())
        {
            while (find != set_p.end() && l >= find->first && r <= find->second)
            {
                set_p.erase(find);
                find = set_p.find({l, r});
            }
            set_p.insert({l, r});
        }
        else
            set_p.insert({l, r});
    }
    
    //answer queries
    unsigned a, b, x, y;
    for (unsigned i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &a, &b, &x, &y);
        bool answer = query_small_range(segment_sets, a, b, x, y);
        // if (k / n <= 1 && b-a+1 >= 1000)
        //     answer = query_large_range(segment_sets, a, b, x, y);
        // else
        //     answer = query_small_range(segment_sets, a, b, x, y);
        if (answer)
            printf("yes\n");
        else
            printf("no\n");
        fflush(stdout);
    }
    return 0;
}
bool query_large_range(SegmentsMap &segment_sets, unsigned a, unsigned b, unsigned x, unsigned y)
{
    vector<unsigned> idx(b - a + 1);
    iota(idx.begin(), idx.end(), a - 1);
    sort(idx.begin(), idx.end(),
         [&segment_sets](size_t i1, size_t i2) { return segment_sets[i1].size() < segment_sets[i2].size(); });

    for (auto p : idx)
    {
        auto &set_p = segment_sets[p];
        if (set_p.empty())
            return false;
        auto find = set_p.find({x, y});
        if (find != set_p.end())
        {
            auto pre = *find;
            if (x > pre.first || y < pre.second)
                return false;
        }
        else
            return false;
    }
    return true;
}
bool query_small_range(SegmentsMap &segment_sets, unsigned a, unsigned b, unsigned x, unsigned y)
{
    for (unsigned p = a; p <= b; p++)
    {
        auto &set_p = segment_sets[p - 1];
        if (set_p.empty())
            return false;
        auto find = set_p.find({x, y});
        if (find != set_p.end())
        {
            auto pre = *find;
            if (x > pre.first || y < pre.second)
                return false;
        }
        else
            return false;
    }
    return true;
}