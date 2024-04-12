#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int list[100001] = {0, };

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int big = 1;
	int small = 1;
	int res = 1;
	for (int i = 1; i < N; i++) {
		if (list[i] > list[i - 1]) {
			small = 1;
			big++;
		} else if (list[i] < list[i-1]) {
			small++;
			big = 1;
		} else {
			small++;
			big++;
		}
		res = max(res, max(small, big));
	}

	cout << res;
}