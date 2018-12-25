#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>

using namespace std;
typedef unsigned long long ULL;

const int N_MIN = 1, N_MAX = 100000000;
const ULL C_MIN = 1, C_MAX = 10000000000000000000ULL;
ULL C[N_MAX];

void gernerate_one_testcase(fstream &f, int N_flag, int C_flag);

int main()
{
    string filename = "../test/zhd_problem2/testcases.txt";
    std::fstream f(filename, f.app | f.out);
    if (!f.is_open())
        cout << "failed to open " << filename << '\n';
    else
    {
        /*
        边缘条件标志
        N       0:随机 1:最小 2:最大
        C       0:随机 1:最小 2:升序 3:降序 4:最大
        */

        int N_flag = 0, C_flag = 3;
        gernerate_one_testcase(f, N_flag, C_flag);
        /** 总共7个case, 包括示例,其余6个的设置为
         * 依次设置的结果是
         * 1 1
         * 0 0
         * 0 1
         * 0 4
         * 0 2
         * 0 3
         * */
    }
    f.close();
    return 0;
}

void gernerate_one_testcase(fstream &f, int N_flag, int C_flag)
{

    cout << "edge flag: " << N_flag << " " << C_flag << endl;

    // set random
    default_random_engine gen(time(NULL));
    uniform_int_distribution dis_N(N_MIN, 10000);
    uniform_int_distribution<ULL> dis_C(C_MIN, C_MAX);

    // set N
    int N;
    // set N
    switch (N_flag)
    {
    case 0:
        N = dis_N(gen);
        break;
    case 1:
        N = N_MIN;
        break;
    default:
        N = N_MAX;
        break;
    }
    f << N << endl;
    // set C

    switch (C_flag)
    {
    case 1:
        fill(C, C + N, C_MIN);
        break;
    case 2:
        for (int n = 0; n < N; n++)
            C[n] = dis_C(gen);
        sort(C, C + N);
        break;
    case 3:
        for (int n = 0; n < N; n++)
            C[n] = dis_C(gen);
        sort(C, C + N, greater<ULL>());
        break;
    case 4:
        fill(C, C + N, C_MAX);
        break;
    default:
        for (int n = 0; n < N; n++)
            C[n] = dis_C(gen);
        break;
    }
    for (int n = 0; n < N; n++)
        f << C[n] << " ";
    f << endl;
}
