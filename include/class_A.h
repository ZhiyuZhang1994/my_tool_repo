// description: 单例类
// author: zhangzhiyu
// date: 2022.4.19

#include "./Singleton.h"
#include <iostream>

class A
{
    SINGLETON_CLASS(A);

public:
    void print_a_b() { std::cout << a << b << std::endl;}

private:
    A(int x, int y) : a(x), b(y) {}

private:
    int a;
    int b;
};

class B
{
    SINGLETON_CLASS(B);

public:
    void print_empty() { std::cout << "empty"<< std::endl;}

private:
    B() = default;
};
