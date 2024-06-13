#include <iostream>
#include <vector>

using namespace std;

int graph[9][9] = {0, };
vector<pair<int, int>> blank;
bool flag = false;

bool check(int i, int j, int num)
{
	for (int k = 0; k < 9; k++) {
		if (graph[k][j] == num || graph[i][k] == num)
			return false;
	}

	int ni = (i / 3) * 3;
	int nj = (j / 3) * 3;

	for (int x = ni; x < ni + 3; x++) {
		for (int y = nj; y < nj + 3; y++) {
			if (graph[x][y] == num)
				return false;
		}
	}

	return true;
}

void dfs(int bIdx)
{
	if (flag)
		return;
	if (bIdx == blank.size())
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		flag = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		int nx = blank[bIdx].first;
		int ny = blank[bIdx].second;

		if (check(nx, ny, i)) {
			graph[nx][ny] = i;
			dfs(bIdx+1);
			graph[nx][ny] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0)
				blank.push_back({i, j});
		}
	}

	dfs(0);

}