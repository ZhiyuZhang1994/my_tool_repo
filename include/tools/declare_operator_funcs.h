// description: 通过宏声明结构体的比较函数
// author: zhangzhiyu
// date: 2022.4.24


// 介绍：此宏实现了一行代码即实现结构体比较函数：
// 客户不需要实现个结构体的比较函数，只需按模板操作即可
// 当前缺陷：
//      1、宏入参个数固定，未扩展为多参数宏


#ifndef INCLUDE_TOOLS_DECLARE_OPERATOR_FUNCS
#define INCLUDE_TOOLS_DECLARE_OPERATOR_FUNCS

#include <iostream>
#include <atomic>
#include <utility>
#include <tuple>

#define DECLARE_OPERATOR_LESS_FUNCS(struct_name, val1, val2, val3) \
    inline bool operator<(const struct_name& left, const struct_name& right) { \
        return std::tie(left.val1, left.val2, left.val3) < std::tie(right.val1, right.val2, right.val3); \
    }

#define DECLARE_OPERATOR_MORE_FUNCS(struct_name, val1, val2, val3) \
    inline bool operator>(const struct_name& left, const struct_name& right) { \
        return std::tie(left.val1, left.val2, left.val3) > std::tie(right.val1, right.val2, right.val3); \
    }

#define DECLARE_OPERATOR_EQUAL_FUNCS(struct_name, val1, val2, val3) \
    inline bool operator==(const struct_name& left, const struct_name& right) { \
        return std::tie(left.val1, left.val2, left.val3) == std::tie(right.val1, right.val2, right.val3); \
    }

#define DECLARE_OPERATOR_NOT_EQUAL_FUNCS(struct_name, val1, val2, val3) \
    inline bool operator!=(const struct_name& left, const struct_name& right) { \
        return !(left == right); \
    }

#define DECLARE_ALL_OPERATOR_FUNCS_3_ARGS(struct_name, val1, val2, val3) \
    DECLARE_OPERATOR_LESS_FUNCS(struct_name, val1, val2, val3); \
    DECLARE_OPERATOR_MORE_FUNCS(struct_name, val1, val2, val3); \
    DECLARE_OPERATOR_EQUAL_FUNCS(struct_name, val1, val2, val3); \
    DECLARE_OPERATOR_NOT_EQUAL_FUNCS(struct_name, val1, val2, val3); \


// 计算宏中参数个数，参考：https://wenku.baidu.com/view/c9fcb9cc142ded630b1c59eef8c75fbfc77d9433.html
#define __COUNT_ARGS(_0, _1, _2, _3, _4, _5, _6, _7, _8, _n, X...) _n
#define COUNT_ARGS(X...) __COUNT_ARGS(, ##X, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define CONNECT_OPERATOR_FUNCS_PREFIX_AND_ARGS_COUNT(x) \
    DECLARE_ALL_OPERATOR_FUNCS_##X##_ARGS

#define ABC(X, struct_name, ...) \
    X(struct_name, __VA_ARGS__)

#define DECLARE_ALL_OPERATOR_FUNCS(struct_name, ...) \
    ABC(CONNECT_OPERATOR_FUNCS_PREFIX_AND_ARGS_COUNT(COUNT_ARGS(__VA_ARGS__)), struct_name, __VA_ARGS__)

#endif