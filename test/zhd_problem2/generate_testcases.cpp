#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

using namespace std;

const int T_MIN = 1, T_MAX = 70;
const int N_MIN = 1, N_MAX = 50;
const int A_MIN = 1, A_MAX = 250;
const int M_MIN = 1, M_MAX = 50;

void gernerate_one_testcase(fstream &f, int edge_flag);
inline int compute_edge_flag(int T_flag, int N_flag, int A_flag, int M_flag);
inline void get_edge_flag(int edge_flag, int &T_flag, int &N_flag, int &A_flag, int &M_flag);

int main()
{
    string filename = "../test/zhd_problem1/testcases.txt";
    std::fstream f(filename, f.app | f.out);
    if (!f.is_open())
        cout << "failed to open " << filename << '\n';
    else
    {
        /*
        边缘条件标志
        T       0:随机 1:最小 2:最大
        N       0:随机 1:最小 2:最大
        A       0:随机 1:最小 2:升序 3:降序 4:最大
        M       0:最小 1:<=N 2:>N 3:最大
        */

        int T_flag = 0, N_flag = 0, A_flag = 0, M_flag = 1;
        int edge_flag = compute_edge_flag(T_flag, N_flag, A_flag, M_flag);
        gernerate_one_testcase(f, edge_flag);
        /** 总共10个case, 包括示例,其余九个的设置为
         * 依次设置的结果是
         * 1 0 0 1
         * 0 1 0 1
         * 0 0 0 2
         * 0 0 1 1
         * 0 0 4 1
         * 2 0 0 1
         * 2 0 4 1
         * 2 2 3 1
         * 2 2 2 1
         * */

    }
    f.close();
    return 0;
}

void gernerate_one_testcase(fstream &f, int edge_flag)
{
    int T_flag, N_flag, A_flag, M_flag;
    get_edge_flag(edge_flag, T_flag, N_flag, A_flag, M_flag);
    cout << "edge flag: " << T_flag << " " << N_flag << " " << A_flag << " " << M_flag << endl;

    // set random
    default_random_engine gen(time(NULL));

    uniform_int_distribution dis_T(T_MIN, T_MAX);
    uniform_int_distribution dis_N(N_MIN, N_MAX);
    uniform_int_distribution dis_A(A_MIN, A_MAX);
    uniform_int_distribution dis_M(M_MIN, M_MAX);

    int T, N, A[250], M;

    // set T
    switch (T_flag)
    {
    case 0:
        T = dis_T(gen);
        break;
    case 1:
        T = T_MIN;
        break;
    default:
        T = T_MAX;
        break;
    }
    //save T
    f << T << endl;

    for (int t = 0; t < T; t++)
    {
        // set N
        switch (N_flag)
        {
        case 0:
            N = dis_N(gen);
            if (N == 1)
                N = 2;
            break;
        case 1:
            N = N_MIN;
            break;
        default:
            N = N_MAX;
            break;
        }
        // set A
        for (int n = 0; n < N; n++)
        {
            A[n] = dis_A(gen);
        }
        switch (A_flag)
        {
        case 1:
            fill(A, A + N, A_MIN);
            break;
        case 2:
            sort(A, A + N);
            break;
        case 3:
            sort(A, A + N, greater<int>());
            break;
        case 4:
            fill(A, A + N, A_MAX);
            break;
        default:
            break;
        }
        // set M
        switch (M_flag)
        {
        case 0:
            M = M_MIN;
            break;
        case 1:
            M = (dis_M(gen) - M_MIN) * (N - N_MIN) / (M_MAX - M_MIN) + N_MIN;
            break;
        case 2:
            M = min((dis_M(gen) - M_MIN) * (N_MAX - N) / (M_MAX - M_MIN) + N + 1, M_MAX);
            break;
        default:
            M = M_MAX;
            break;
        }

        // save testcase

        f << N << endl;
        for (int n = 0; n < N; n++)
            f << A[n] << " ";
        f << endl;
        f << M << endl;
    }
    f << endl;
}

inline int compute_edge_flag(int T_flag, int N_flag, int A_flag, int M_flag)
{
    return (((T_flag * 3) + N_flag) * 5 + A_flag) * 4 + M_flag;
}
inline void get_edge_flag(int edge_flag, int &T_flag, int &N_flag, int &A_flag, int &M_flag)
{
    M_flag = edge_flag % 4;
    A_flag = (edge_flag /= 4) % 5;
    N_flag = (edge_flag /= 5) % 3;
    T_flag = edge_flag / 3;
}
