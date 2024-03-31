#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 300001;
vector<int> graph[MAX];
int dist[MAX];
int N, M, K, X;

void bfs(int start)
{
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		for (int i = 0; i < graph[n].size(); i++) {
			int next = graph[n][i];
			if (dist[next] > dist[n] + 1) {
				q.push(next);
				dist[next] = dist[n] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K >> X;

	while (M--)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);;
	}

	for (int i = 0; i <= N; i++)
		dist[i] = INT_MAX;

	bfs(X);

	bool is_res = false;
	for (int i = 1; i <= N; i++){
		if (dist[i] == K) {
			cout << i << '\n';
			is_res = true;
		}
	}
	if (!is_res)
		cout << -1 << '\n';
	return 0;
}