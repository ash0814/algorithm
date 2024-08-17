#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n, m;
	cin >> n >> m;

	vector<vector<int>> f;
	bool visited[501] = {0, };
	f.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		f[a].push_back(b);
		f[b].push_back(a);
	}

	int cnt = 0;
	queue<int> f1;
	visited[1] = true;
	for (auto n : f[1]) {
		cnt++;
		visited[n] = true;
		f1.push(n);
	}

	while (!f1.empty())
	{
		int x = f1.front();
		f1.pop();

		for (auto n : f[x]) {
			if (!visited[n]) {
				visited[n] = true;
				cnt++;
			}
		}
	}

	cout << cnt;
}