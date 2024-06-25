#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	if (a.first.size() == b.first.size()) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	}
	return a.first.size() < b.first.size();
}

int main()
{
	int N;
	cin >> N;

	vector<pair<string, int>> list;
	while (N--)
	{
		string serial;
		cin >> serial;
		int sum = 0;
		for (int i = 0; i < serial.size(); i++) {
			if ('0' <= serial[i] && serial[i] <= '9')
				sum += (int)(serial[i] - '0');
		}

		list.push_back({serial, sum});
	}

	sort(list.begin(), list.end(), cmp);

	for (auto s : list)
	{
		cout << s.first << "\n";
	}
}