#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstring>

using namespace std;

int N, M;
int s, e;

vector<vector<pair<int, int>>> city;

void dks()
{
	vector<int> dist(N + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 거리, 도시
	vector<bool> visited(N + 1, false);
	dist[s] = 0;
	pq.push({0, s});

	while (!pq.empty())
	{
		int d = pq.top().first;
		int c = pq.top().second;
		pq.pop();
		if (visited[c])
			continue;
		visited[c] = true;
		for (auto next : city[c]) {
			int nc = next.first;
			int nd = d + next.second;
			if (!visited[nc] && dist[nc] > nd)
			{
				dist[nc] = nd;
				pq.push({nd, nc});
			}
		}
	}
	cout << dist[e];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	city.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		city[a].push_back({b, w});
	}
	cin >> s >> e;
	dks();
}