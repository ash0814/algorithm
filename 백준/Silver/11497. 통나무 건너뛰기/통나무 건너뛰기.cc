#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solution()
{
	int N;
	cin >> N;
	vector<int> list;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}

	sort(list.begin(), list.end());

	int idx = 0;
	vector<int> res;

	while (idx < N) {
		res.push_back(list[idx]);
		idx += 2;
	}
	if (idx == N)
		idx = N - 1;
	else
		idx = N - 2;
	while (idx >= 0) {
		res.push_back(list[idx]);
		idx -= 2;
	}


	int sub = abs(res[N-1] - res[0]);
	for (int i = 0; i < N - 1; i++) {
		sub = max(sub, abs(res[i] - res[i+1]));
	}
	cout << sub << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		solution();
	}
}