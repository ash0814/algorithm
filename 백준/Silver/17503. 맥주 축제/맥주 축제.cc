#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<pair<int, int>> list;

	for (int i = 0; i < K; i++) {
		int v, c;
		cin >> v >> c;
		list.push_back({v, c});
	}

	sort(list.begin(), list.end(), cmp);

	priority_queue<int, vector<int>, greater<int>> pq;

	long long total = 0;

	for (auto b : list) {
		pq.push(b.first);
		total += b.first;

		if (pq.size() > N)
		{
			total -= pq.top();
			pq.pop();
		}

		if (pq.size() == N && total >= M) {
			cout << b.second;
			return 0;
		}
	}

	cout << -1;
	return 0;
}