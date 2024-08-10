#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int isStack[100001];
	int res[100001];
	deque<int> q;
	for (int i = 0; i < N; i++)
		cin >> isStack[i];
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (!isStack[i]) {
			q.push_front(num);
		}
	}

	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int num;
		cin >> num;

		q.push_back(num);
		res[i] = q.front();
		q.pop_front();
	}
	for (int i = 0; i < C; i++)
		cout << res[i] << " ";
}