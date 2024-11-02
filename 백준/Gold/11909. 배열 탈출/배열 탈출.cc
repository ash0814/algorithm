#include <iostream>
#include <queue>
#define MAX 2223
#define INF 10000000

using namespace std;

int arr[MAX][MAX];
int dp[MAX][MAX];
int n;
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };


void dijkstra(int x, int y) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {x, y} });


	dp[x][y] = 0;

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int money = pq.top().first;
		pq.pop();

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next_money = money;
			if (!(1 <= x && x <= n && 1 <= y && y <= n))
				continue;
			if (arr[nx][ny] >= arr[x][y]) {
				next_money += (arr[nx][ny] - arr[x][y] + 1);
			}
			if (next_money >= dp[nx][ny])
				continue;

			dp[nx][ny] = next_money;
			pq.push({ next_money, {nx, ny} });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INF;
		}
	}
	dijkstra(1, 1);

	cout << dp[n][n] << "\n";

	return 0;
}