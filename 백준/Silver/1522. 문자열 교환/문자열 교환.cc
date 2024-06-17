#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int acnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a')
			acnt++;
	}

	int res = 987654;

	for (int i = 0; i < str.length(); i++) {
		int cnt = 0;
		for (int j = i; j < i + acnt; j++) {
			int idx = j % str.length();
			if (str[idx] == 'b')
				cnt++;
		}
		res = min(cnt, res);
	}
	cout << res;
}