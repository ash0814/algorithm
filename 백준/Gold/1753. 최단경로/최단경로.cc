#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;

int V, E, K;
vector<vector<pair<int, int>>> graph;

void bfs()
{
	vector<int> dist(V+1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // distance, dest
	pq.push({0, K});
	dist[K] = 0;

	while (!pq.empty())
	{
		int d = pq.top().first;
		int n = pq.top().second;
		pq.pop();

		for (auto g : graph[n]) {
				int nn = g.first;  // 인접 정점 번호
            	int nd = d + g.second;

				if (nd < dist[nn])  // 지금 계산한 것이 기존 거리값보다 작다면
            	{
                	dist[nn] = nd;  // 거리값 업데이트
               		pq.push({ nd, nn });  // 우선순위 큐에 넣기
            	}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;

	graph.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
	bfs();
}