#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	if (K >= N)
	{
		cout << 0;
		return 0;
	}

	int res = 0;
	while (1)
	{
		int cnt = 0;
		int tmp = N;

		while (tmp > 0) {
			if (tmp % 2)
				cnt++;
			tmp /= 2;
		}

		if (K >= cnt)
			break;

		N++;
		res++;
	}
	cout << res;
	return 0;
}