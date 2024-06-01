#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	vector<int> list;
	int start = 1;
	int end = 0;
	int total = 0;

	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		list.push_back(l);
		if (end < l)
			end = l;
		total += l;
	}

	int res = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += list[i] / mid;
		}

		if (cnt >= M) {
			start = mid + 1;
			res = mid;
		} else {
			end = mid - 1;
		}
	}

	cout << res;
}