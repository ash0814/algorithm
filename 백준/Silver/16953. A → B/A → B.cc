#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;

	int cnt = 0;

	queue<long long> q;
	q.push(A);
	map<long long, int> visited;
	bool found = false;
	while (!q.empty()) {
		long long x = q.front();
		q.pop();
		if (x == B) {
			found = true;
			break;
		}
		cnt++;

		if (x * 2 <= B && visited.find(x * 2) == visited.end()) {
			q.push(x * 2);
			if (visited[x] + 1 > cnt)
				visited.insert({x * 2, cnt});
			else
				visited.insert({x * 2, visited[x] + 1});
		}
		if (x * 10 + 1 <= B && visited.find(x * 10 + 1) == visited.end()) {
			q.push(x * 10 + 1);
			if (visited[x] + 1 > cnt)
				visited.insert({x * 10 + 1, cnt});
			else
				visited.insert({x * 10 + 1, visited[x] + 1});
		}
	}

	if (found)
		cout << visited[B] + 1;
	else
		cout << -1;
}