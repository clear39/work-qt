#ifndef IS_SAME_H
#define IS_SAME_H
#include <iostream>
#include <type_traits>
#include <cstdint>

//  https://zh.cppreference.com/w/cpp/types/is_same

void print_separator()
{
    std::cout << "-----\n";
}

void test_is_same()
{
    std::cout << std::boolalpha;

    print_separator();

    std::cout << std::is_same<int, int32_t>::value << '\n';   // true
    std::cout << std::is_same<int, int64_t>::value << '\n';   // false
    std::cout << std::is_same<float, int32_t>::value << '\n'; // false

    print_separator();

    std::cout << std::is_same<int, int>::value << "\n";          // true
    std::cout << std::is_same<int, unsigned int>::value << "\n"; // false
    std::cout << std::is_same<int, signed int>::value << "\n";   // true

    print_separator();

    // 不同于其他类型， 'char' 既非 'unsigned' 亦非 'signed'
    std::cout << std::is_same<char, char>::value << "\n";          // true
    std::cout << std::is_same<char, unsigned char>::value << "\n"; // false
    std::cout << std::is_same<char, signed char>::value << "\n";   // false
}


#endif // IS_SAME_H
