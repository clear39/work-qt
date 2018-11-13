#include <QCoreApplication>
#include <iostream>
#include "move.h"
#include "remove_reference.h"
#include "is_same.h"
#include "boolalpha.h"
#include "bool_constant.h"

#include "memoryblock.h"
#include <vector>

#include "test.h"

#include "parser.h"
#include "read_file.h"
#include "move_forward_test.h"


#include "test_bind.h"

#include "test_string.h"

#include "test_getopt.h"

using namespace std;



int main(int argc,char** argv){
    test_getopt_main(argc,argv);

    //test_string();

    //test_bind();

    //test_move_forward_main();

    //test_read_dir();


    char data_copy[] = "write /proc/1/oom_score_adj -1000\n";

    parse_state state;
    state.line = 0;
    state.ptr = &data_copy[0];
    state.nexttoken = 0;

    next_token(&state);


/*    char* buff = new char[512]{0};
    int len = __basename_r("/init/ooo/",buff,512);

    char* buff = new char[512]{0};
    int len = __dirname_r("/init",buff,512);

    cout << len << " " << buff << endl;

    */


    cout << get_stem_from_spec("/(vendor|system/vendor)/overlay(/.*)?") << " "<< endl;






/*
   // Create a vector object and add a few elements to it.
   vector<MemoryBlock> v;
   v.push_back(MemoryBlock(25));
   v.push_back(MemoryBlock(75));

   // Insert a new element into the second position of the vector.
   v.insert(v.begin() + 1, MemoryBlock(50));




    test_boolalpha();

    std::cout << "****************************************" << std::endl;

    test_move();

    std::cout << "****************************************" << std::endl;

    test_remove_reference();


    std::cout << "****************************************" << std::endl;


    test_is_same();


    std::cout << "****************************************" << std::endl;


    test_bool_constant();

    std::cout << "****************************************" << std::endl;
    */
    return 0;
}
