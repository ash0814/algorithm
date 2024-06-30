#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[26];

bool bfs(int i, int j)
{
	queue<int> q;
	bool visited[26] = {false, };
	q.push(i);

	while (!q.empty()) {
		int n = q.front();
		visited[n] = true;
		q.pop();

		for (auto c : graph[n]) {
			if (!visited[c]) {
				if (c == j)
					return true;
				q.push(c);
			}
		}
	}
	return false;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b;
		string is;
		cin >> a >> is >> b;

		graph[a - 'a'].push_back(b - 'a');
	}

	int M;
	cin >> M;
	while (M--)
	{
		char a, b;
		string is;
		cin >> a >> is >> b;

		bool isTrue = bfs(a - 'a', b - 'a');
		if (isTrue)
			cout << "T\n";
		else
			cout << "F\n";
	}
}