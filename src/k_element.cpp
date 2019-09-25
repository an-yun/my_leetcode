#include "zuo/ioutils.hpp"
#include <algorithm>
#include <ctime>
#include <random>
#include <string>
#include <vector>


template <class Iterator, class Compare>
Iterator k_element(Iterator b, Iterator e, size_t k, Compare comp)
{
    size_t n = std::distance(b, e);

    // out of range
    if (k > n || k < 1)
        return e;

    // for small array, use sort
    if (n < 11)
    {
        std::sort(b, e, comp);
        return std::next(b, k - 1);
    }

    //for large array
    size_t group = n / 5, last_group = n % 5;
    Iterator sub_b = b;
    for (size_t i = 0; i < group; ++i)
    {
        auto e1 = std::next(sub_b, 5);
        std::sort(sub_b, e1, comp);
        sub_b = e1;
    }
    auto e1 = std::next(sub_b, last_group);
    std::sort(sub_b, e1, comp);

    //select mid and partition
    auto pivot = *std::next(b, group / 2 * 5 + 2);
    auto low = b, high = b;
    for (auto i = b; i < e; ++i)
    {
        if (comp(pivot, *i))      // *i > pivot
            ;                     //do nothing
        else if (comp(*i, pivot)) // *i < pivot
        {
            // the swap order is very important! edge case: i==high? 
            std::swap(*i, *high); 
            std::swap(*low, *high);
            ++low;
            ++high;
        }
        else // *i == pivot
        {
            std::swap(*high, *i);
            ++high;
        }
    }
    size_t d1 = std::distance(b, low), d2 = std::distance(b, high);
    if (k <= d1)
        return k_element(b, low, k, comp);
    else if (k <= d2)
        return std::next(b, k - 1);
    else
        return k_element(high, e, k - d2, comp);
}

template <class T>
typename std::vector<T>::iterator k_element(std::vector<T> &v, size_t k)
{
    return k_element(v.begin(), v.end(), k, std::less<T>());
}

template <class T, unsigned Size>
T *k_element(T v[Size], size_t k)
{
    return k_element(v, v + Size, k, std::less<T>());
}

template <class T>
T *k_element(T *v, size_t size, size_t k)
{
    return k_element(v, v + size, k, std::less<T>());
}

int main()
{
    std::default_random_engine gen(std::time(nullptr));
    std::uniform_int_distribution<size_t> size_d(100, 1000);
    std::uniform_int_distribution<size_t> k_d(103, 1007);
    std::uniform_int_distribution<int> num_d1(-10e3, 10e3);
    std::uniform_int_distribution<int> num_d2(-20, 20);
    const size_t T = 150;
    println();
    for (size_t i = 0; i < T; ++i)
    {
        auto size = size_d(gen);
        std::vector<int> nums(size);
        for (size_t j = 0; j < size; ++j)
            nums[j] = num_d2(gen);
        auto k = k_d(gen) % size + 1;
        auto k_num = *k_element(nums, k);
        std::sort(nums.begin(), nums.end());
        if (nums[k - 1] != k_num)
        {
            print("the", k, "-element is", k_num, "?", false);
            println();
        }

        for (size_t j = 0; j < size; ++j)
            nums[j] = num_d1(gen);
        k = k_d(gen) % size + 1;
        k_num = *k_element(nums, k);
        std::sort(nums.begin(), nums.end());
        if (nums[k - 1] != k_num)
        {
            print("the", k, "-element is", k_num, "?", false);
            println();
        }
        size = size_d(gen);
        int *array_num = new int[size];
        for (size_t j = 0; j < size; ++j)
            array_num[j] = num_d1(gen);
        k = k_d(gen) % size + 1;
        k_num = *k_element(array_num, size, k);
        std::sort(array_num, array_num + size);
        if (array_num[k - 1] != k_num)
        {
            print("the", k, "-element is", k_num, "?", false);
            println();
        }
        delete[] array_num;
    }
    println("ok");
    return 0;
}