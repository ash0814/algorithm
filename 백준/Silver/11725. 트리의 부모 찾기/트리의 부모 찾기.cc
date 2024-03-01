#include <iostream>
#include <vector>

using namespace std;

int visited[100001] = {0, };
int parent[100001] = {0, };
vector<vector<int>> tree(100001);

void dfs(int v)
{
	visited[v] = 1;

	for (int i = 0; i < tree[v].size(); i++)
	{
		int node = tree[v][i];
		if (visited[node] == 0)
		{
			parent[node] = v;
			dfs(node);
		}
	}

}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", parent[i]);
	}
}