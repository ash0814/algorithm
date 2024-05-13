#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,pair<int, int>> a, pair<int,pair<int, int>> b)
{
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	return a.second.first > b.second.first;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<pair<int, pair<int, int>>> list;
	int t = 0;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		bool flag = false;
		for (int i = 0; i < list.size(); i++) {
			if (list[i].first == num) {
				list[i].second.first++;
				flag = true;
				break;
			}
		}

		if (!flag) {
			if (list.size() < N) {
				list.push_back({num, {1, t}});
			} else {
				list.pop_back();
				list.push_back({num, {1, t}});
			}
		}

		sort(list.begin(), list.end(), cmp);
		t++;
	}

	set<int> res;
	for (auto n : list)
		res.insert(n.first);

	for (auto n : res)
		cout << n << " ";
}