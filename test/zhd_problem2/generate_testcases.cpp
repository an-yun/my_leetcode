#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <numeric>

using namespace std;
typedef unsigned long long ULL;

const int N_MIN = 1, N_MAX = 100000000;
const ULL C_MIN = 1, C_MAX = 10000000000000000000ULL;

void gernerate_one_testcase(fstream &f, int N_flag, int C_flag);

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
        N       0:随机 1:最小 2:最大
        C       0:随机 1:最小 2:升序 3:降序 4:最大
        */

        int  N_flag = 0, C_flag = 0;
        gernerate_one_testcase(f, N_flag, C_flag);
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

void gernerate_one_testcase(fstream &f, int N_flag, int C_flag)
{

    cout << "edge flag: " << N_flag << " " << C_flag << endl;

    // set random
    default_random_engine gen(time(NULL));
    uniform_int_distribution dis_N(N_MIN, N_MAX);
    uniform_int_distribution<ULL> dis_C(C_MIN, C_MAX);


    //9 testcases
    f << 9 << endl;

    for (int t = 0; t < 9; t++)
    {
        // set N
        switch (N_flag)
        {
        case 0:

            break;
        case 1:

            break;
        default:

            break;
        }
        // set C

        switch (C_flag)
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
    }
    f << endl;
}
