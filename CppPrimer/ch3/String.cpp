#include <string>
#include <iostream>
using std::string;
using std::cout;
int main() {
	string s1 = "中国";
	string s4(10, 'c');
	cout << s1;
	cout << s4;
	return 0;
}