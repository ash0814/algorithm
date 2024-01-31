#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> list;
	while (N--)
	{
		int start, finish;
		cin >> start >> finish;

		list.push_back({start, finish});
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	sort(list.begin(), list.end());
	pq.push(list[0].second);

	for (int i = 1; i < list.size(); i++)
	{
		pq.push(list[i].second);
		if (pq.top() <= list[i].first)
			pq.pop();
	}

	cout << pq.size() << '\n';
}