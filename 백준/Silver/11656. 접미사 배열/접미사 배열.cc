#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> m;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		string suffix = "";
		for (int j = i; j < str.length(); j++)
		{
			suffix += str[j];
		}
		m.insert({suffix, i});
	}

	for (auto s : m)
	{
		cout << s.first << endl;
	}
}