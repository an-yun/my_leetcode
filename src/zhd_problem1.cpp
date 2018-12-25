#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

int T, N, A[250], M;

bool check_validity(int max_pages)
{
    int min_students = 1, current_pages = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > max_pages)
            return false;
        if (current_pages + A[i] > max_pages)
        {
            min_students++;
            current_pages = A[i];
            if (min_students > M)
                return false;
        }
        else
            current_pages += A[i];
    }
    return true;
}

int min_max_pages()
{
    // for special cases
    if (M > N)
        return -1;
    if (M == N)
        return *max_element(A, A + N);

    //binary search
    int end = accumulate(A, A + N, 0), start = end / M;
    int min_pages = __INT_MAX__;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (check_validity(mid))
        {
            min_pages = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return min_pages;
}

int main()
{
    while (scanf("%d", &T) == 1)
    {
        for (int i = 0; i < T; i++)
        {
            scanf("%d", &N);
            for (int n = 0; n < N; n++)
                scanf("%d", A + n);
            scanf("%d", &M);
            printf("%d\n", min_max_pages());
        }
    }
    return 0;
}