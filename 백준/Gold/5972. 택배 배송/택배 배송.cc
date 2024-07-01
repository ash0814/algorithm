#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;

void bfs()
{
	vector<int> dist(N + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, 1});
	dist[1] = 0;

	while (!pq.empty()) {
		int dst = pq.top().first;
		int n = pq.top().second;
		pq.pop();

		for (auto g : graph[n]) {
			int nn = g.first;
			int nd = dst + g.second;

			if (nd < dist[nn]) {
				dist[nn] = nd;
				pq.push({nd, nn});
			}
		}
	}
	cout << dist[N];
}

int main()
{
	cin >> N  >> M;

	graph.resize(N + 1);

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	bfs();
}