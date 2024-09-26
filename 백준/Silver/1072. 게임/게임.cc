#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long x, y;
	cin >> x >> y;
	long long z = (y * 100) / x;

	if (z >= 99) {
		cout << -1;
		return 0;
	}

	int start = 0;
	int end = 1000000000;

	while (start <= end) {
		int mid = (start + end) / 2;
		int nz = ((y + mid) * 100) / (x + mid);
		if (z < nz) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	cout << start;
	return 0;
}