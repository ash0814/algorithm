#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	priority_queue<int> pq;
	while (N--)
	{
		int n;
		cin >> n;
		pq.push(n);
	}

	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}