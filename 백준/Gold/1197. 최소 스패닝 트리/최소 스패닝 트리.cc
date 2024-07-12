#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> edges;
int parent[10001];

int find_root(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y) {
	int xr = find_root(x);
	int yr = find_root(y);

	if (xr != yr)
		parent[yr] = xr;
}

int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({c, {a, b}});
	}

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	vector<pair<int, pair<int, int>>> res;
	int answer = 0;
	for (int i = 0; i < E; i++)
	{
		pair<int, pair<int, int>> cur = edges[i];

		int a = cur.second.first;
		int b = cur.second.second;

		if (find_root(a) == find_root(b))
			continue;

		res.push_back(cur);
		answer += cur.first;
		union_root(a, b);

		if (res.size() == V - 1)
			break;
	}

	cout << answer;
}