#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 2147483646;
int N, M;
int visited[51] = {0, };
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int dist = MAX;


void comb(int idx, int cnt)
{
	if (cnt == M) {
		int sum = 0;
		for (auto h : house) {
			int min_dis = MAX;
			for (int i = 0; i < chicken.size(); i++) {
				if (visited[i] == 1) {
					int dis = abs(h.first - chicken[i].first)
						+ abs(h.second - chicken[i].second);
					if (dis < min_dis)
						min_dis = dis;
				}
			}
			sum += min_dis;
		}
		if (sum < dist)
			dist = sum;
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			comb(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	int city[51][51];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 2)
				chicken.push_back({i, j});
			if (num == 1)
				house.push_back({i, j});
		}
	}

	comb(0, 0);

	cout << dist;
}