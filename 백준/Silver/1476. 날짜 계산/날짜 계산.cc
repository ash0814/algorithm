#include <iostream>

using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	// 1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19

	int e = 0;
	int s = 0;
	int m = 0;
	int year = 1;
	while (1)
	{
		if (e == E-1 && s == S-1 && m == M-1)
		{
			cout << year << endl;
			return 0;
		}
		e = (e + 1) % 15;
		s = (s + 1) % 28;
		m = (m + 1) % 19;
		year++;
	}
	return 0;
}