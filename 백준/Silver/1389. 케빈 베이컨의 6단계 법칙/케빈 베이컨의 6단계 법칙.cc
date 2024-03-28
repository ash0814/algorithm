#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int friends[101][101];
int cnt[101];
int kb[101];
bool visited[101];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		for (int j = 1; j <= N; j++)
		{
			if (friends[i][j] == 1 && !visited[j])
			{
				visited[j] = true;
				q.push(j);
				cnt[j] = cnt[i] + 1;
			}
		}
	}
}

int getMin()
{
	int m = kb[1];
	int res = 1;

	for (int i = 2; i <= N; i++) {
		if (m > kb[i])
		{
			m = kb[i];
			res = i;
		}
	}

	return res;
}

int main()
{

	cin >> N >> M;

	while (M--)
	{
		int x, y;
		cin >> x >> y;
		friends[x][y] = 1;
		friends[y][x] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		bfs(i);

		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			kb[i] += cnt[j];
		}
		for (int j = 0; j <= N; j++)
		{
			visited[j] = 0;
			cnt[j] = 0;
		}
	}
	cout << getMin();

	return 0;
}