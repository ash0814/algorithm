#include <iostream>

using namespace std;

int main()
{
	int N, F;
	cin >> N >> F;

	N = N - N% 100;

	for (int num = N; num <= N + 100; num++) {
		if (num % F == 0) {
			int res = num % 100;
			if (res < 10)
				cout << 0 << res;
			else
				cout << res;
			return 0;
		}
	}
	return 0;
}