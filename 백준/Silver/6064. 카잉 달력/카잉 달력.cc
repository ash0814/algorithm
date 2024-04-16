#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int T;
	cin >>T;

	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int lcm = (M * N) / gcd(M, N);
		int k = -1;

		for (int i = x; i <= lcm; i+= M) {
			int yy = i % N;
			if (yy == 0)
				yy = N;
			if (yy == y)
			{
				k = i;
				break;
			}
		}

		cout << k << '\n';
	}
}