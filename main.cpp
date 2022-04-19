#include "./include/class_A.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

int main()  {
    A::GetInstance(2, 3)->print_a_b();
    std::cout << "--------Split line-------------" << std::endl;
    A::GetInstance(2, 3)->print_a_b();
    getchar();
}