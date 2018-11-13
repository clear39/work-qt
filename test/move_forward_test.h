#ifndef MOVE_FORWARD_TEST_H
#define MOVE_FORWARD_TEST_H
#include <iostream>
using namespace std;

/*
template<typename T>
void print(T& t){
    cout << "lvalue" << endl;
}
template<typename T>
void print(T&& t){
    cout << "rvalue" << endl;
}

template<typename T>
void TestForward(T && v){
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}
*/
int test_move_forward_main(){
    /*
     * TestForward(1);
    int x = 1;
    TestForward(x);
    TestForward(std::forward<int>(x));
    */
    return 0;
}
#endif // MOVE_FORWARD_TEST_H
