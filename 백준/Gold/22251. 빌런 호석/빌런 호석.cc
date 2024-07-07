#include <iostream>

using namespace std;

int N, K, P, X;
bool floor[10][7] = {
		{true, true, true, false, true, true, true},		 // 0
		{false, false, true, false, false, true, false}, // 1
		{true, false, true, true, true, false, true},		 // 2
		{true, false, true, true, false, true, true},		 // 3
		{false, true, true, true, false, true, false},	 // 4
		{true, true, false, true, false, true, true},		 // 5
		{true, true, false, true, true, true, true},		 // 6
		{true, false, true, false, false, true, false},	 // 7
		{true, true, true, true, true, true, true},			 // 8
		{true, true, true, true, false, true, true}			 // 9
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> P >> X;

	int res = 0;

	for (int f = 1; f <= N; f++)
	{
		if (f == X)
			continue;
		int cnt = 0;

		int origin = X;
		int change = f;

		for (int i = 0; i < K; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (floor[origin % 10][j] != floor[change % 10][j])
					cnt++;
			}
			origin /= 10;
			change /= 10;
		}

		if (cnt <= P)
			res++;
	}
	cout << res;
}
