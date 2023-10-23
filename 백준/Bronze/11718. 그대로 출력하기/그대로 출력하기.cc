#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
    int N = 100;
	while(N--) {
		getline(cin, str);
		if(str == "") break;

		cout << str << '\n';
	}

	return 0;
}