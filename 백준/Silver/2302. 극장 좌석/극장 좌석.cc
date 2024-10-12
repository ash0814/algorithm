#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	bool list[41] = {0, };
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		list[num] = true;
	}

	int cnt = 0;
	vector<int> group;
	for (int i = 1; i <= N; i++) {
		if (list[i]) {
			group.push_back(cnt);
			cnt = 0;
		} else {
			cnt++;
		}
	}
	if (cnt > 0)
		group.push_back(cnt);

	long long fib[41] = {0, };
    fib[0] = 1;
	fib[1] = 1;
	fib[2] = 2;
	fib[3] = 3;
	for (int i = 4; i <= N; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	long long res = 1;
	for (auto n : group) {
		res *= fib[n];
	}
	cout << res;
}