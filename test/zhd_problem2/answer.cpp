#include <algorithm>
#include <cstdio>
#include <limits>
#include <numeric>
#include <set>

using namespace std;
typedef unsigned long long ULL;

int main()
{
    int T, N;
    multiset<ULL> nums;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d", &N);
        ULL num,inversion_count = 0;
        for (int n = 0; n < N;n++)
        {
            
            scanf("%llu", &num);
            inversion_count += distance(nums.upper_bound(num), nums.end());
            nums.insert(num);
        }
        printf("%llu\n", inversion_count);
    }
    return 0;
}
