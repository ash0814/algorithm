#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		a %= 10;
		int res;
		if (a == 1) {
			res = 1;
		} else if (a == 2) {
			int arr[4] = {2, 4, 8, 6};
			res = arr[(b-1) % 4];
		} else if (a == 3) {
			int arr[4] = {3, 9, 7, 1};
			res = arr[(b-1) % 4];
		} else if (a == 4) {
			int arr[2] = {4, 6};
			res = arr[(b-1)%2];
		} else if (a==5) {
			res = 5;
		} else if (a == 6) {
			res = 6;
		} else if (a == 7) {
			int arr[4] = {7, 9, 3, 1};
			res = arr[(b-1) % 4];
		} else if (a == 8) {
			int arr[4] = {8, 4, 2, 6};
			res = arr[(b-1) % 4];
		} else if (a == 9) {
			int arr[2] = {9, 1};
			res = arr[(b-1) % 2];
		} else {
			res = 10;
		}
		cout << res << '\n';
	}

}
