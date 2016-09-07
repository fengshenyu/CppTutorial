#include <iostream>
using namespace std;
int main() {
    int a = 3;
    const int* u;
    u = &a; //初始化u
    cout << "*u=" << *u << endl;

    /* 试图通过u修改u指向的内容,直接报错.
        *u = 3; 
        cout << "*u=" << *u << endl;
    */

    /*通过另外一个变量的指针修改u指向的内容是正确的.*/
    int b = 4;
    u = &b;
    cout << "*u=" << *u << endl;

    /*通过另外一个指针修改u指向的内容也是正确的.*/
    int *c = &b;
    *c = 100;
    cout << "*u=" << *u << endl;
}