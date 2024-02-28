#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int cnt = 0;
vector<map<int, int>> graph(100001);
int visited[100001] = {0, };
int N;

void dfs(int R)
{
	visited[R] = ++cnt;

	for (auto n : graph[R])
	{
		if (visited[n.first] == 0)
			dfs(n.first);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int  M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].insert({b, 1});
		graph[b].insert({a, 1});
	}

	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << visited[i] << '\n';
}