#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited[21] = {0, };
int graph[21][21];
vector<int> start;
vector<int> link;
priority_queue<int, vector<int>, greater<int>> pq;
int N;

void comb(int idx, int cnt) {
	if (cnt == N / 2) {
		for (int i = 0; i < N; i++) {
			if (visited[i])
				start.push_back(i);
			else
				link.push_back(i);
		}
		int start_p = 0;
		int link_p = 0;

		for (int a = 0; a < N / 2 - 1; a++) {
			for (int b = a + 1; b < N / 2; b++) {
				start_p += graph[start[a]][start[b]] + graph[start[b]][start[a]];
				link_p += graph[link[a]][link[b]] + graph[link[b]][link[a]];
			}
		}


		int diff = start_p > link_p ? start_p - link_p : link_p - start_p;
		pq.push(diff);

		start.clear();
		link.clear();

		return;
	}

	for (int i = idx; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			comb(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	comb(0, 0);

	cout << pq.top();
}