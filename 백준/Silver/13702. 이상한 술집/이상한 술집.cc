#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<long long> list;

	long long start = 0;
	long long end = 0;
	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		list.push_back(m);
		if (end < m)
			end = m;
	}

	long long res = 0;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long cnt = 0;

		if (mid > 0) {
			for (auto m : list) {
				if (m == 0)
					continue;
				cnt += m / mid;
			}
		}

		if (cnt >= K || mid == 0) {
			res = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	cout << res;
}