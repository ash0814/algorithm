#include <iostream>

using namespace std;

int n;
int reCnt = 0;
int dpCnt = 0;

int recursive(int num)
{
	if (num == 1 || num == 2) {
		reCnt++;
		return 1;
	}
	return recursive(num - 1) + recursive(num - 2);
}

int dp(int num) {
	int fib[50] = {0, };
	fib[1] = 1;
	fib[2] = 1;
	for (int i = 3; i <= n; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		dpCnt++;
	}
	return fib[num];
}

int main()
{
	cin >> n;

	recursive(n);
	dp(n);
	cout << reCnt << " " << dpCnt;
}