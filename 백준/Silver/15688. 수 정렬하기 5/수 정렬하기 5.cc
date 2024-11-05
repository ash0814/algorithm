#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
}