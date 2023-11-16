#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	cin >> N;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		pq.push({b, a});
	}

	while (!pq.empty())
	{
		cout << pq.top().second << " " << pq.top().first << '\n';
		pq.pop();
	}

	return 0;
}
