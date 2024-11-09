#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> list;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}
	sort(list.begin(), list.end());

	int left = 0;
	int right = 1;
	long long res = INT_MAX;
	while (left < N && right < N)
	{
		long long sub = list[right] - list[left];
		if (sub == M) {
			res = sub;
			break;
		} else if (sub < M) {
			right++;
			continue;
		}

		left++;
		if (sub < res)
			res = sub;
	}
	cout << res;
	return 0;
}