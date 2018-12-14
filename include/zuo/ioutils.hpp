#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
void print_vector(const std::vector<T> &vec)
{
    for (auto e : vec)
        std::cout << e << " ";
    std::cout << std::endl;
}