#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int graph[101][101] = {0, };
int N;
set<int> list[101];

bool check(int i, int j)
{
	queue<int> q;
	int visited[101] = {0, };

	for (auto n : list[i])
		q.push(n);
	while (!q.empty()) {
		int num = q.front();
		visited[num] = true;
		q.pop();

		if (num == j)
			return true;
		for (auto n : list[num]) {
			if (!visited[n])
				q.push(n);
		}
	}
	return false;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				list[i].insert(j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check(i, j))
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
}