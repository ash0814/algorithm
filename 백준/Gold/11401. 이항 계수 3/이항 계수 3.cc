#include <iostream>

using namespace std;

const long long mod = 1000000007;

long long pow(long long n, long long k)
{
	long long ret = 1;

	while (k)
	{
		if (k % 2)
			ret = (ret * n) % mod;

		n = (n * n) % mod;
		k /= 2;
	}

	return ret;
}

int main()
{
	int n, k;
	cin >> n >> k;

	long long A = 1, B = 1;

	for (int i = n; i >= n - k + 1; i--)
		A = (A * i) % mod;
	for (int i = 2; i <= k; i++)
		B = (B * i) % mod;

	cout << (A * pow(B, mod - 2)) % mod;

	return 0;
}