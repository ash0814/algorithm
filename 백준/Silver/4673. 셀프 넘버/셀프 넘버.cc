#include <iostream>

using namespace std;

int check(int n)
{
	int num = n;

	while (n != 0) {
		num = num + (n % 10);
		n /= 10;
	}

	return num;
}

int main()
{
	int N = 0;
	bool list[10001] = {false, };

	for (int i = 1; i <= 10000; i++) {
		N = check(i);

		if (N <= 10000)
			list[N] = true;
	}

	for (int i = 1; i <= 10000; i++) {
		if (!list[i])
			cout << i << '\n';
	}
}