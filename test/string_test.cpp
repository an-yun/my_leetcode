#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

int main()
{
    const char s[] = "abc";
    std::string buff(100, ' ');
    auto end_pos = std::copy(std::cbegin(s), std::cend(s), buff.begin()); //也可以直接声明std::string buff("abc");
    [](const std::string &buff) {
        std::cout << buff << std::endl;
    }(buff); //对于可以自定义的函数
    std::copy(std::cbegin(s), std::cend(s), --end_pos); // 覆盖'\0'
    [](const char *buff) { // 需要const char * 的C函数
        fwrite(buff, strlen(buff), 1, stdout);
        printf("\n");
    }(buff.c_str());
    // 需要char * 的C函数
    [s](char *buff) {
        sprintf(buff, "%s %s %s", s,s,s);
    }(buff.data());
    std::cout << buff << std::endl;
    return 0;
}