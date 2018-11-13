#ifndef TEST_STRING_H
#define TEST_STRING_H
#include <stdio.h>
#include <string>
#include <iostream>
 #include <string.h>
using namespace std;
void test_string(){
    string fqName("android.hardware.audio@2.0::IDevicesFactory");
    size_t idx = fqName.find("::");

    string packageAndVersion = fqName.substr(0, idx);//    packageAndVersion= "android.hardware.audio@2.0"
    string ifaceName = fqName.substr(idx + strlen("::"));

    cout << "packageAndVersion:" << packageAndVersion << endl;

    cout << "ifaceName:" << ifaceName << endl;
}

#endif // TEST_STRING_H
