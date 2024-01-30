#include <iostream>

using namespace std;

int main()
{
	string cap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string small = "abcdefghijklmnopqrstuvwxyz";
	string s;
	string res = "";
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
			res += small[(s[i] - 'a' + 13) % 26];
		else if ('A' <= s[i] && s[i] <= 'Z')
			res += cap[(s[i] - 'A' + 13) % 26];
		else
			res += s[i];
	}
	cout << res << endl;
}