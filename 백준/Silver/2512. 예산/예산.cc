#include <iostream>

using namespace std;

int list[10001];
int N;
int total;

int check(int money) {
	int t = total;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] > money) {
			ret += money;
		} else {
			ret += list[i];
		}
	}
	return ret;
}

int main()
{
	cin >> N;

	int start = 1;
	int end = 0;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		end = end < list[i] ? list[i] : end;
	}

	cin >> total;
	int res;
	int current = start;
	while (start <= end) {
		int mid = (start + end) / 2;

		int c = check(mid);
		if (c > current && c <= total) {
			res = mid;
			start = mid + 1;
			current = c;
		} else {
			end = mid - 1;
		}
	}

	cout << res;
}