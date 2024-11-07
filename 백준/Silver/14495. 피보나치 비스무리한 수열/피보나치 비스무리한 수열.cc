#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	long long fib[120] = {0, };
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;
	fib[3] = 1;

	for (int i = 4; i <= N; i++) {
		fib[i] = fib[i - 1] + fib[i - 3];
	}

	cout << fib[N];
}