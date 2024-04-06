#include <iostream>

using namespace std;

string res = "";

bool setString(int xcnt)
{
	if (xcnt % 2 == 1)
		return false;
	while (xcnt >= 4) {
		res += "AAAA";
		xcnt -= 4;
	}
	while (xcnt > 0) {
		res += "BB";
		xcnt -= 2;
	}

	return true;
}

int main()
{
	string input;
	cin >> input;

	int xcnt = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'X')
			xcnt++;
		else {
			if (!setString(xcnt))
			{
				cout << -1;
				return 0;
			}
			res += '.';
			xcnt = 0;
		}
	}
	if (!setString(xcnt))
		cout << -1;
	else
		cout << res;
	return 0;
}