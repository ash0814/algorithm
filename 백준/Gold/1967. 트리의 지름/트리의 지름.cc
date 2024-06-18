#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> tree[10002];
priority_queue<int> pq;

vector<int> dfs(int idx) {
	vector<int> res;
	priority_queue<int> list;

	for (auto c : tree[idx]) {
		list.push(dfs(c.first)[0] + c.second);
	}

	while (res.size() < 2) {
		if (list.empty())
			res.push_back(0);
		else
		{
			res.push_back(list.top());
			list.pop();
		}
	}
	pq.push(res[0] + res[1]);
	return res;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		tree[a].push_back({b, w});
	}

	vector<int> r = dfs(1);
	cout << pq.top();
}