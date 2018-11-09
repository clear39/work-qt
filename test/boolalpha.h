#ifndef BOOLALPHA_H
#define BOOLALPHA_H

#include <sstream>
#include <locale>
#include <iostream>

void test_boolalpha()
{

    std::cout << "true is " << true << std::endl;               //  true is 1
    std::cout << "false is " << false << std::endl;             //  false is 0

    // 运行下面这个语句, 在输出流中的bool值将发生变化
    std::cout << std::boolalpha;
    std::cout << "true is " << true << std::endl;               //  true is true
    std::cout << "false is " << false << std::endl;             //  false is false

    // 运行下面这个语句, 在输出流中的bool值将恢复成0, 1值
    std::cout << std::noboolalpha;
    std::cout << "true is " << true << std::endl;               //  true is 1
    std::cout << "false is " << false << std::endl;             //  false is 0




    // boolalpha 输出
   std::cout << std::boolalpha
             << "boolalpha true: " << true << '\n'                              //  boolalpha true: true
             << "boolalpha false: " << false << '\n';                           //  boolalpha false: false


   std::cout << std::noboolalpha
             << "noboolalpha true: " << true << '\n'                            //  noboolalpha true: 1
             << "noboolalpha false: " << false << '\n';                         //  noboolalpha false: 0


   // boolalpha 分析
   bool b1, b2;
   std::istringstream is("true false");
   is >> std::boolalpha >> b1 >> b2;
   std::cout << '\"' << is.str() << "\" parsed as " << b1 << ' ' << b2 << '\n'; //  "true false" parsed as 1 0
}


#endif // BOOLALPHA_H
