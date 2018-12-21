#include <algorithm>
#include <iostream>
#include <vector>

// 打印普通类型
template <typename T>
inline void print(const T &t)
{
    std::cout << t;
}
template <typename T>
inline void println(const T &t)
{
    std::cout << t << std::endl;
}

// 打印vector
template <typename T>
inline void print(const std::vector<T> &t)
{
    std::cout << '[';
    size_t t_size = t.size();
    if (t_size > 0)
    {
        for (size_t i = 1; i < t_size; i++)
            std::cout << t[i - 1] << ", ";
        std::cout << t[t_size - 1];
    }
    std::cout << ']';
}
// 打印vector
template <typename T>
inline void println(const std::vector<T> &t)
{
    print(t);
    std::cout << std::endl;
}

// 泛化的打印函数
template <typename T, typename... Args>
inline void print(const T &t, const Args... rest)
{
    print(t);
    std::cout << ", ";
    print(rest...);
}

template <typename T, typename... Args>
inline void println(const T &t, const Args... rest)
{
    print(t, rest...);
    std::cout << std::endl;
}
