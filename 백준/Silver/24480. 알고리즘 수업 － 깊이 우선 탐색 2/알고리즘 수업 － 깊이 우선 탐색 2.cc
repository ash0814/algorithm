#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001] = {false, };
int N, M, R;
vector<vector<int>> graph;
int res[100001] = {0, };
int cnt = 0;

void dfs(int r)
{
	visited[r] = true;
	res[r] = ++cnt;

	for (auto n : graph[r])
	{
		if (!visited[n])
			dfs(n);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;
	graph.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(graph[i].rbegin(), graph[i].rend());

	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << res[i] << '\n';
}