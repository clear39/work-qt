#include <stdio.h>
#include <iostream>


#include "a_start.h"

int main(int argc,char** argv){
    for(int i = 0; i< argc;i++){
        std::cout << argv[i] << std::endl;
    }


    A_Start_Main();


    std::cout << "###########################################" << std::endl;

}
