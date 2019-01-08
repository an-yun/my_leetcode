#include <algorithm>
#include <iostream>
#include <vector>

// 打印普通类型
template <typename T>
inline void print(const T &t)
{
    std::cout << t;
}
// 打印vector
template <typename T>
inline void print(const std::vector<T> &t)
{
    print('[');
    size_t t_size = t.size();
    if (t_size > 0)
    {
        for (size_t i = 1; i < t_size; i++)
        {
            print(t[i - 1]);
            print(", ");
        }
        print(t[t_size - 1]) ;
    }
    print(']');
}
// 泛化的打印函数
template <typename T, typename... Args>
inline void print(const T &t, const Args... rest)
{
    print(t);
    std::cout << ", ";
    print(rest...);
}

template <typename T>
inline void println(const T &t)
{
    print(t);
    std::cout << std::endl;
}

template <typename T, typename... Args>
inline void println(const T &t, const Args... rest)
{
    print(t, rest...);
    std::cout << std::endl;
}
