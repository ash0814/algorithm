#include <iostream>
#include <vector>

using namespace std;

int list[100001] = {0, };
int N, M;

int countBlueray(int m)
{
	int cnt = 1;
	int s = 0;
	for (int i = 0; i < N - 1; i++) {
		s += list[i];
		if (s + list[i + 1] > m) {
			s = 0;
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	cin >> N >> M;

	int start = -1;
	int end = 0;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		end += list[i];
		start = start < list[i] ? list[i] : start;
	}

	int res;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (countBlueray(mid) <= M) {
			end = mid - 1;
			res = mid;
		} else {
			start = mid + 1;
		}
	}

	cout << res;
}