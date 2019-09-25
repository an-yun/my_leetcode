#include "zuo/ioutils.hpp"
#include <string>
#include <vector>

using namespace std;

void compute_pi(const string &pattern, vector<unsigned> &pi);
size_t kmp(const string &text, const string &pattern, size_t start = 0);

int main()
{
    string text("ababacaabcabacabababaca"), pattern("ababaca");
    for (size_t p = kmp(text, pattern, 0); p != string::npos; p = kmp(text, pattern, p + 1))
    {
        println("============================");
        println("0123456789012345678901234567");
        println(text);
        for (size_t i = 0; i < p; ++i)
            cout << ' ';
        println(pattern);
        println("============================");
    }
}

size_t kmp(const string &text, const string &pattern, size_t start)
{
    unsigned m = text.size(), n = pattern.size();
    if(start + n > m)
        return string::npos;
    vector<unsigned> pi(n, 0);
    compute_pi(pattern, pi);
    size_t q = 0;
    for (size_t i = start; i < m;++i)
    {
        while(q >0 && pattern[q] != text[i])
            q = pi[q-1];
        if(pattern[q] == text[i])
            ++q;
        if(q == n)
            return i + 1 - n;
    }
    return string::npos;
}

void compute_pi(const string &pattern, vector<unsigned> &pi)
{
    unsigned n = pi.size();
    pi[0] = 0;
    unsigned k = 0;
    for (unsigned q = 1; q < n;++q)
    {
        while(k > 0 && pattern[k] != pattern[q] )
            k = pi[k];
        if(pattern[k] == pattern[q])
            k += 1;
        pi[q] = k;
    }
}