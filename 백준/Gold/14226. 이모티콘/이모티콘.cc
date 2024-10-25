#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int S;
	cin >> S;

	queue<pair<int, pair<int, int>>> q;
	q.push({0, {1, 0}});
	bool visited[1001][1000] = {0, };
	visited[1][0] = true;
	while (!q.empty()) {
		int t = q.front().first;
		int e = q.front().second.first;
		int c = q.front().second.second;

		q.pop();

		if (e == S) {
			cout << t;
			break;
		}
		if (!visited[e][e]) {
			q.push({t+1, {e, e}});
			visited[e][e] = true;
		}
		if (e-1 > 1 && !visited[e-1][c]) {
			visited[e-1][c] = true;
			q.push({t+1, {e - 1, c}});
		}
		if (e + c <= 1000 && !visited[e+c][c]) {
			visited[e+c][c] = true;
			q.push({t+1, {e + c, c}});
		}
	}
}