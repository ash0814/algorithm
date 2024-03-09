#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited[10001];
vector<vector<int>> computer(10001);
vector<int> list;
int N, M;

void dfs(int v)
{
	visited[v] = 1;
	list.push_back(v);

	for (auto n : computer[v])
	{
		if (visited[n] == 0)
			dfs(n);
	}
}

int main()
{
	cin >> N >> M;
	vector<int> results;
	int resultMax = 0;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		computer[b].push_back(a);
	}

	vector<pair<int, int>> res;

	for (int i =1; i <= N; i++)
	{
		dfs(i);
		res.push_back({list.size(), i});

		for (int j = 0; j <= N; j++)
			visited[j] = 0;
		list.clear();
	}

	sort(res.begin(), res.end());
	int maxSize = res[res.size() - 1].first;
	for (auto n : res)
	{
		if (n.first == maxSize)
			cout << n.second << " ";
	}
}