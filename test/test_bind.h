#ifndef TEST_BIND_H
#define TEST_BIND_H

#include <iostream>
#include <functional>
#include <random>
#include <memory>


//学习bind的用法
void f(int n1, int n2, int n3, const int & n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << "\n";
}

int g(int n1)
{
    return n1 + 100;
}


int h(int n1)
{
    return n1 + 100;
}


struct Foo {
    Foo()=default;
    Foo(int a,int b = 1){data = a;data2=b;}
    Foo(const Foo & a)
    {
        data = a.data;
        std::cout << "复制构造" << std::endl;
    }
    void print_sum(int n1, int n2)
    {
        std::cout << n1 + n2 << '\n';
    }

    void printPath(const char* path){
        std::cout << path << '\n';
    }

    int data = 10;
    int data2 = 1;
};


//////////////////////////////////////////////////////////////////////////
//std::bind的不同的placeholders个数证明调用函数体时需要传入的参数量及位置
//std::bind的时候目标的函数的参数的顺序与bind的时候的顺序的一一对应的
//////////////////////////////////////////////////////////////////////////
const Foo gFoo{100,50};
int test_bind()
{
    /*
    auto fh = std::bind(h,std::placeholders::_1,"/system/manifest.xml");
    //fh(1);

    int n = 7;
    auto f1 = std::bind(f, std::placeholders::_4, std::placeholders::_1, std::placeholders::_3, std::cref(n), n);
    //第一位置 目标函数（f）的第一个参数 是调用时传的第二个参数
    //第二位置 目标函数（f）的第二个参数 是调用时传的第一个参数
    //第三位置 目标函数（f）的第三个参数 是43
    //第四位置 目标函数（f）的第四个参数 是n的按址传递
    //第五位置 目标函数（f）的第五个参数 是n
    n = 10;
    f1(1, 2,43,5);//相当于f(2,1,43,10,7);

    using namespace std::placeholders;
    auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
    //第一位置 目标函数f的第一个参数 是调用时传的第三个参数
    //第二位置 目标函数f的第二个参数 是调用时传的g(第三个参数)
    //第三位置 目标函数f的第三个参数 是调用时传的第三个参数
    //第四位置 目标函数f的第四个参数 是4
    //第五位置 目标函数f的第五个参数 是5
    //由此可见，调用时的第一个参数和第二个参数是没有用的。调用时你把第一个或第二个参数传多少都是没有用的
    f2(1000, 2000, 55);//f(55,g(55),55,4,5);

    // common use case: binding a RNG with a distribution
    std::default_random_engine e;
    std::uniform_int_distribution<> d(0, 10);
    std::cout << d(e) << std::endl;//生成一个随机数

    std::function<int()> rnd = std::bind(d, e);//rnd就相当于d(e)
    for (int n = 0; n < 10; ++n)
        std::cout << rnd() << ' ';
    std::cout << '\n';
    */

    //绑定类成员函数用对象的指针
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, std::placeholders::_1);
    f3(5);

    // 绑定类成员变量
    std::cout << "测试绑定类成员" << std::endl;
    auto f4 = std::bind(&Foo::data, std::placeholders::_1);
    std::cout << f4(foo) << '\n';
    //std::cout << f4(&foo) << '\n';//尝试传入类对象指针编译不通过
    std::cout << f4(std::cref(foo)) << '\n';//引用包装传递

    std::cout << "===============================" << std::endl;
    auto f6 = std::bind(&Foo::printPath, std::placeholders::_1,"/system/manifest.xml");
    f6(foo);


    //测试发现vs2013不支持Foo的智能指针做为f4的参数
    //system("pause");

    return 0;
}


#endif // TEST_BIND_H
