#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Baseball {
	string input;
	int strike;
	int ball;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Baseball> list;
	int res = 0;

	for (int i = 0; i < N; i++) {
		string a;
		int b, c;
		cin >> a >> b >> c;

		Baseball B;
		B.input = a;
		B.strike = b;
		B.ball = c;
		list.push_back(B);
	}

	for (int num = 123; num <= 987; num++) {
		int a = num / 100;
		int b = (num / 10) % 10;
		int c = num % 10;

		if (a == b || b == c || c == a)
			continue;
		if (a == 0 || b == 0 || c == 0)
			continue;

		a += '0';
		b += '0';
		c += '0';

		int isOK = true;
		for (auto base : list) {
			int st = 0;
			int ba = 0;
			if (base.input[0] == a)
				st++;
			if (base.input[1] == b)
				st++;
			if (base.input[2] == c)
				st++;
			if (base.input[1] == a || base.input[2] == a)
				ba++;
			if (base.input[0] == b || base.input[2] == b)
				ba++;
			if (base.input[0] == c || base.input[1] == c)
				ba++;

			if (!(st == base.strike && ba == base.ball)) {
				isOK = false;
			}
		}
		if (isOK) {
			res++;
		}
	}
	cout << res;
	return 0;
}