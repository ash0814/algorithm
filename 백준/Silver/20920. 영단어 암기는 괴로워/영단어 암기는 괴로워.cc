#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string ,int> a, pair<string ,int> b)
{
	if (a.second == b.second) {
		if (a.first.size() == b.first.size())
			return a.first < b.first;
		return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> words;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s.size() < M)
			continue;
		if (words.find(s) != words.end()) {
			words[s]++;
		} else {
			words.insert({s, 1});
		}
	}

	vector<pair<string, int>> list;
	for (auto w : words)
	{
		list.push_back({w.first, w.second});
	}

	sort(list.begin(), list.end(), cmp);

	for (auto w : list)
	{
		cout << w.first << "\n";
	}
}