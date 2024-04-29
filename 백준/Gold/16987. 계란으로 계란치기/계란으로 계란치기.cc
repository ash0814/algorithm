#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> eggs; // first : 내구도, second: 무게
int ans = 0;

void dfs(int n)
{
	if (n == eggs.size()) {
		int cnt = 0;
		for (auto e : eggs) {
			if (e.first <= 0)
				cnt++;
		}
		if (cnt > ans)
			ans = cnt;
		return ;
	}

	if (eggs[n].first <= 0) {
		dfs(n + 1);
	} else {
		bool flag = false;
		for (int i = 0; i < eggs.size(); i++) {
			if (i == n || eggs[i].first <= 0)
				continue;
			flag = true;
			eggs[i].first -= eggs[n].second;
			eggs[n].first -= eggs[i].second;
			dfs(n + 1);
			eggs[i].first += eggs[n].second;
			eggs[n].first += eggs[i].second;
		}
		if (!flag)
		dfs(n + 1);
	}
}

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		int s, w;
		cin >> s >> w;
		eggs.push_back({s, w});
	}

	dfs(0);

	cout << ans;
}