#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	int x, y;
	cin >> x >> y;
	pair<int, int> start = {x + 32768, y+32768};

	vector<pair<int, int>> coord;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		coord.push_back({x+32768, y+32768});
	}
	cin >> x >> y;
	pair<int, int> penta = {x + 32768, y+32768};


	bool visited[101] = {0, };
	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty()) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		int p_dis = abs(penta.first - qx) + abs(penta.second - qy);
		if (p_dis <= 1000) {
			cout << "happy\n";
			return ;
		}

		for (int i = 0; i < coord.size(); i++) {
			if (!visited[i] && abs(qx - coord[i].first) + abs(qy - coord[i].second) <= 1000) {
				visited[i] = true;
				q.push(coord[i]);
			}
		}
	}
	cout << "sad\n";
	return ;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solution();
	}
}