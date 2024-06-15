#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>

using namespace std;

int res = INT_MAX;
int N;
vector<pair<int, int>> list;

void dfs(int idx, int sour, int bitter, bool use)
{
	if (idx == N)
	{
		if (use)
			res = min(res, abs(bitter - sour));
		return;
	}

	dfs(idx + 1, sour, bitter, use);
	dfs(idx + 1, sour * list[idx].first, bitter + list[idx].second, true);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int S, B;
		cin >> S >> B;
		list.push_back({S, B});
	}

	dfs(0, 1, 0, false);
	cout << res;
}