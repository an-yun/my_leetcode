#include<pthread.h>
#include<functional>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<vector>
#include <utility>
#include <tuple>
using namespace std;
#pragma comment(lib, "pthread")

class Foo
{
    pthread_barrier_t barrier1; 
    pthread_barrier_t barrier2; 
    
public:
    Foo(){
        pthread_barrier_init(&barrier1, NULL,2);
        pthread_barrier_init(&barrier2, NULL,2);
    }
    
    ~Foo(){
        pthread_barrier_destroy(&barrier1);
        pthread_barrier_destroy(&barrier2);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pthread_barrier_wait(&barrier1);
    }

    void second(function<void()> printSecond) {
        pthread_barrier_wait(&barrier1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        pthread_barrier_wait(&barrier2);
    }

    void third(function<void()> printThird) {
        pthread_barrier_wait(&barrier2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
void printFirst()
{
    printf("first");
}
void printSecond()
{
    printf("second");
}
void printThird()
{
    printf("third");
}
void* run(void *arg)
{
    auto foo_fun_run = static_cast<tuple<Foo*,void (Foo::*)(function<void()>), void (*)()> *>(arg);
    auto foo = get<0>(*foo_fun_run);
    auto fun = get<1>(*foo_fun_run);
    auto run = get<2>(*foo_fun_run);
    (foo->*fun)(run);
    return arg;
}
int main()
{
    vector<int> order{1, 3, 2};
    pthread_t pids[3];
    Foo f;
    vector<tuple<Foo*,void (Foo::*)(function<void()>), void (*)()>> functions{
        {&f,&Foo::first, &printFirst},
        {&f,&Foo::second, &printSecond},
        {&f,&Foo::third, &printThird}};
    for (int i = 0; i < 3;++i)
        pthread_create(&pids[i], NULL, run, static_cast<void *> (&functions[order[i]-1]));
    void *tret;
    pthread_join(pids[0],&tret);
    pthread_join(pids[1],&tret);
    pthread_join(pids[2],&tret);
    return 0;
}
