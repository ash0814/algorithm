#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int big[100001] = {0, };
	int small[100001] = {0, };
	int list[100001] = {0, };

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	big[0] = 1;
	small[0] = 1;
	int res = 1;
	for (int i = 1; i < N; i++) {
		if (list[i] > list[i - 1]) {
			small[i] = 1;
			big[i] = big[i-1] + 1;
		} else if (list[i] < list[i-1]) {
			small[i] = small[i - 1] + 1;
			big[i] = 1;
		} else {
			small[i] = small[i-1] + 1;
			big[i] = big[i-1] + 1;
		}
		res = max(res, max(small[i], big[i]));
	}

	cout << res;
}