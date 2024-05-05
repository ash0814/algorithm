#include <iostream>

using namespace std;

long long bun[51];
long long patty[51];
long long burger[51];

long long eat(long long l, long long x)
{
	if (l == 0)
		return 1;
	if (x == 1)
		return 0;

	if (x <= 1 + burger[l - 1])
		return eat(l - 1, x - 1);
	if (x == (1 + burger[l - 1] + 1))
		return patty[l-1] + 1;
	if (x <= (1 + burger[l-1] + 1 + burger[l - 1]))
		return patty[l - 1] + 1 + eat(l - 1, x - (1 + burger[l-1] + 1));
	return patty[l-1] + 1 + patty[l - 1];
}

int main()
{
	int N;
	long long X;

	cin >> N >> X;

	bun[0] = 0;
	patty[0] = 1;
	burger[0] = 1;

	for (int i = 1; i <= N; i++) {
		bun[i] = bun[i - 1] * 2 + 2;
		patty[i] = patty[i - 1] * 2 + 1;
		burger[i] = bun[i] + patty[i];
	}

	cout << eat(N, X);
}