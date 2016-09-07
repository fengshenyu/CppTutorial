#include <iostream>
using namespace std;
template <typename T>
struct tvec2 {
    typedef T               value_type;
    typedef std::size_t     size_type;
    typedef tvec2<T>        type;
    value_type  x;
    value_type  y;
};
int main() {
    tvec2<int> a;
    a.x = 1;
    a.y = 2;
    cout << "x=" << a.x << "y=" <<a.y << endl;
}