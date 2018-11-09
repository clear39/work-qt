#ifndef BOOL_CONSTANT_H
#define BOOL_CONSTANT_H


//  https://zh.cppreference.com/w/cpp/types/integral_constant


#include <iostream>
#include <type_traits>

int test_bool_constant()
{
    typedef std::integral_constant<int, 2> two_t;
    typedef std::integral_constant<int, 4> four_t;

    std::cout << "two_t:" << two_t::value << ",four_t:" << four_t::value << std::endl;

//  static_assert(std::is_same<two_t, four_t>::value,"two_t and four_t are not equal!");
//  error: static assertion failed: "two_t and four_t are not equal!"

    static_assert(two_t::value*2 == four_t::value,"2*2 != 4");

    enum class my_e {
       e1,
       e2
    };

    typedef std::integral_constant<my_e, my_e::e1> my_e_e1;
    typedef std::integral_constant<my_e, my_e::e2> my_e_e2;

//  static_assert(my_e_e1::value == my_e_e2::value,"my_e_e1::value != my_e::e2");
//  error: static assertion failed: "my_e_e1::value != my_e::e2"

    static_assert(std::is_same<my_e_e2, my_e_e2>::value,"my_e_e2 != my_e_e2");

    std::cout << "std::is_same<my_e_e1, my_e_e2>::value:" << std::is_same<my_e_e1, my_e_e2>::value << std::endl;
}


#endif // BOOL_CONSTANT_H
