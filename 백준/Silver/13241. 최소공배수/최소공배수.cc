#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	long long r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

long long lcm(long long a, long long b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	long long a, b;
	cin >> a >> b;

	cout << lcm(a, b);
}