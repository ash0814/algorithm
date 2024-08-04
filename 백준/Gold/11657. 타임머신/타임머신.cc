#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> edges[501];
long long dist[501];
int N, M;

bool bf(int start)
{
	dist[start] = 0;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < edges[i].size(); j++) {
				int n = edges[i][j].first;
				int c = edges[i][j].second;

				if (dist[i] != INT_MAX && dist[n] > dist[i] + c) {
					dist[n] = dist[i] + c;
					if (k == N)
						return true;
				}
			}
		}

	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a].push_back({b, c});
	}

	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
	}
	bool isCycle = bf(1);

	if (isCycle)
		cout << -1 << '\n';
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INT_MAX)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}


}