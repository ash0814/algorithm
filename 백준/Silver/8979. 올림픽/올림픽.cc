#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int K;

struct Medal {
	int gold;
	int silver;
	int bronze;
};

struct comp {

	bool operator() (pair<int, Medal> a, pair<int, Medal> b)
	{
		if (a.second.gold == b.second.gold)
		{
			if (a.second.silver == b.second.silver) {
				if (a.second.bronze == b.second.bronze) {
					if (a.first == K)
						return false;
					if (b.first == K)
						return true;
				}
				return a.second.bronze < b.second.bronze;
			}
			return a.second.silver < b.second.silver;
		}
		return a.second.gold < b.second.gold;
	}
};

int main()
{
	int N;
	priority_queue <pair<int, Medal>, vector<pair<int, Medal>>, comp> list;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		int num;
		Medal m;
		cin >> num >> m.gold >> m.silver >> m.bronze;
		list.push({num, m});
	}
	int rank = 1;

	while (!list.empty())
	{
		if (list.top().first == K)
			cout << rank;
		list.pop();
		rank++;
	}
}