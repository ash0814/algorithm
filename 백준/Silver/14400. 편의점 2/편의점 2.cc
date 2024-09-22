#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> list;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		list.push_back({x, y});
	}

	sort(list.begin(), list.end());
	int resX = list[(n - 1) / 2].first;
	sort(list.begin(), list.end(), [](pair<int, int>a, pair<int, int>b){ return a.second > b.second;});
	int resY = list[(n - 1) / 2].second;

	long long dis = 0;
	for (auto p : list)
	{
		dis += abs(p.first - resX) + abs(p.second - resY);
	}
	cout << dis;
}