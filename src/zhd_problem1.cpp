#include <algorithm>
#include <cstdio>

using namespace std;

int T, N, A[250], M;

int min_max_pages()
{
    // for special cases
    if (M > N)
        return -1;
    if (M == N)
        return *max_element(A, A + N);

    //dvide and conquer
    
    return 0;
}

int main()
{
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for (int n = 0; n < N; n++)
            scanf("%d", A + n);
        scanf("%d", &M);
        printf("%d\n", min_max_pages());
    }
    return 0;
}