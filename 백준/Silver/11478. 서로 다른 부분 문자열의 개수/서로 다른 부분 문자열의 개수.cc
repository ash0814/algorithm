#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		string s = "";
        for (int j = i; j < str.length(); j++) {
            s += str[j];
            m.insert({s, 1});
        }
    }
	cout << m.size();
}