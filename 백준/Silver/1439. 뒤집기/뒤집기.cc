#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int one = 0;
	int zero = 0;

	char c = str[0];
	if (c == '1')
		one++;
	else
		zero++;

	for (int i = 1; i < str.length(); i++) {
		if (str[i] != c) {
			c = str[i];
			if (c == '1')
				one++;
			else
				zero++;
		}
	}
	cout << min(one, zero);
}