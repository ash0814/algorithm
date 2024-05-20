#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int N, K;
int visited[300001] = {0, };
// int t[200001] = {0, };

void bfs(int idx)
{
	queue<int> qu;
	qu.push(idx);

	while (!qu.empty())
	{
		int x = qu.front();
		qu.pop();

		if (x == K) {
			cout << visited[K];
			return;
		}
		/*
		if (0<=2 * x && 2 * x < 100001 && !visited[2*x]) {
			visited[2 * x] = visited[x];
			qu.push(2 * x);
		}
		if (x - 1 >= 0 && x - 1 < 100001 && visited[x - 1] == 0) {
			qu.push(x - 1);
			visited[x-1] = visited[x] + 1;
		}
		if (0 <= x + 1 && x + 1 < 100001 && visited[x + 1] == 0) {
			qu.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}
		*/

		int list[3] = {2 * x, x-1, x+1};
		for (auto i : list) {
			if (0 <= i && i <= 100000 && visited[i] == false) {
				qu.push(i);
				if (i == 2 * x)
					visited[i] = visited[x];
				else
					visited[i] = visited[x] + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	bfs(N);
}