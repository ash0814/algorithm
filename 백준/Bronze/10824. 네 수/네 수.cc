#include <iostream>

using namespace std;

long long getInt(string str)
{
	long long toInt= 0;
	for (int i = 0; i < str.length(); i++)
		toInt = toInt * 10 + str[i] - '0';
	return toInt;
}

int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	string ab = a + b;
	string cd = c + d;

	long long res = getInt(ab) + getInt(cd);

	cout << res << endl;
}