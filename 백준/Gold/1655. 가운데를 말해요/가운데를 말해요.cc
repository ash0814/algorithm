#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (max_pq.empty())
			max_pq.push(num);
		else if (max_pq.size() == min_pq.size())
			max_pq.push(num);
		else
			min_pq.push(num);

		if (!max_pq.empty() && !min_pq.empty() && (min_pq.top() < max_pq.top()))
		{
			int a = max_pq.top();
			int b = min_pq.top();

			max_pq.pop();
			min_pq.pop();

			max_pq.push(b);
			min_pq.push(a);
		}

		cout << max_pq.top() << "\n";
	}
}