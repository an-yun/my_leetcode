#include <fstream>
#include <random>

using namespace std;

const int T_MIN = 1, T_MAX = 70;
const int N_MIN = 1, N_MAX = 50;
const int A_MIN = 1, A_MAX = 250;
const int M_MIN = 1, M_MAX = 50;

random_device rd;  // 将用于为随机数引擎获得种子
mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine

uniform_int_distribution dis_T(T_MIN, T_MAX);
uniform_int_distribution dis_N(N_MIN, N_MAX);
uniform_int_distribution dis_A(A_MIN, A_MAX);
uniform_int_distribution dis_M(M_MIN, M_MAX);

void gernerate_one_testcase(fstream &f, bool valid = true)
{
    int T = dis_T(gen);
    f << T << endl;
    for (int t = 0; t < T; t++)
    {
        int N = dis_N(gen);
        if(!valid && N==1)
            N = 2;
        f << N << endl;
        for (int n = 0; n < N; n++)
        {
            f << dis_A(gen) << " ";
        }
        f << endl;
        if (valid)
            f << (dis_M(gen) - M_MIN) * (N_MAX - N) / (M_MAX - M_MIN) + N;
        else
            f << (dis_M(gen) - M_MIN) * (N-N_MIN) / (M_MAX - M_MIN) + N_MIN-1;
        f << endl;
    }
}

int main()
{

    return 0;
}