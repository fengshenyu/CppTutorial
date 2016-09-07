#include <iostream>
using namespace std;
int main() {
    int d = 1;
    int* const w = &d;

    /* 试图修改w,直接报错.
    int e =2;
    w = &e;
    
    */

    /*可以修改w指向的内容*/
    *w = 6;
    cout << "*w=" << *w << endl;
    *w = 7;
    cout << "*w=" << *w << endl;
    return 0;
}