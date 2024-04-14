#include <iostream>

using namespace std;

string toStr(int n)
{
	string res = "";
	while (n > 0) {
		res += (n % 10) + '0';
		n /= 10;
	}
	return res;
}

int main()
{
	string num;
	cin >> num;

	int y;
	if (num.length() == 1) {
		y = num[0] - '0';
	} else {
		y = 987654321;
	}
	int cnt = 0;

	while (y >= 10) {
		y = 0;
		for (int i = 0; i < num.length(); i++) {
			y += (num[i] - '0');
		}
		num = toStr(y);
		cnt++;
	}

	cout << cnt << "\n";
	if (y == 3 || y == 6 || y == 9)
		cout << "YES";
	else
		cout << "NO";
}