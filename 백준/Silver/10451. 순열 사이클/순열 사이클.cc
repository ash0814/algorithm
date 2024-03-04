#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> list(1001);
int visited[1001];

void dfs(int v)
{
	visited[v] = 1;

	for (auto n : list[v]){
		if (visited[n] == 0)
			dfs(n);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 0; i <= N; i++){
			visited[i] = 0;
			list[i].clear();
		}

		for (int i = 1; i <= N; i++)
		{
			int v;
			cin >> v;
			list[i].push_back(v);
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}