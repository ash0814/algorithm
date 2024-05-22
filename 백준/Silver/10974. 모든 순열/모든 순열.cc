#include <iostream>
#include <vector>

using namespace std;

int N;
int list[9] = {0, };
int visited[9] = {0, };
vector<int> ans;

void dfs(int idx) {
	if (ans.size() == N) {
		for (auto n : ans)
			cout << n << " ";
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans.push_back(i);
			dfs(i);
			visited[i] = false;
			ans.pop_back();
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		list[i] = i;
	}

	dfs(1);
}