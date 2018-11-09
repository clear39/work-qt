#ifndef TEST2_H
#define TEST2_H



//  https://zh.cppreference.com/w/cpp/types/remove_reference

#include <iostream> // std::cout
#include <type_traits> // std::is_same

template<class T1, class T2>
void print_is_same() {
  std::cout << std::is_same<T1, T2>() << '\n';
}

void test_remove_reference() {
  std::cout << std::boolalpha;

  print_is_same<int, int>();
  print_is_same<int, int &>();
  print_is_same<int, int &&>();

  print_is_same<int, std::remove_reference<int>::type>();           //  true
  print_is_same<int, std::remove_reference<int &>::type>();         //  true
  print_is_same<int, std::remove_reference<int &&>::type>();        //  true

}


#endif // TEST2_H
