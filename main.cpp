#include "./include/test_moudle.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

int main()  {
    A::get_instance(2, 3)->print_a_b();
    std::cout << "--------Split line-------------" << std::endl;
    B::get_instance()->print_empty();
    A::get_instance(2, 3)->print_a_b();

    // 测试类自注册及初始化
    class_repository::get_instance()->active();
    getchar();
}