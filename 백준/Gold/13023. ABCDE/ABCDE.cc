#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> f[2001];
bool visited[2001] = {false, };
bool flag = false;

void dfs(int start, int cnt)
{
	if (cnt >= 5) {
		flag = true;
		return;
	}

	for (auto n : f[start]) {
		if (!visited[n]) {
			visited[n] = true;
			dfs(n, cnt + 1);
			visited[n] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		f[a].push_back(b);
		f[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		dfs(i, 1);
		if (flag)
		{
			printf("1");
			return 0;
		}
	}
	printf("0");
	return 0;
}