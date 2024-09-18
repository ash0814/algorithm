#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N, M;
	cin >> N >> M;

	vector<long long> list;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		list.push_back(num);
	}

	sort(list.begin(), list.end());

	long long left = 1;
	long long right = M * list[0];
	long long res = right;

	while (left <= right) {
		long long p = 0;
		long long mid = (left + right) / 2;
		for (auto n : list) {
			p += mid / n;
		}
		if (p >= M) {
			if (res > mid)
				res = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	cout << res;
}