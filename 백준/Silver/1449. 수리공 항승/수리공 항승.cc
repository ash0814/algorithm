#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	bool pipe[1001] = {false, };
	vector<int> fix;

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		fix.push_back(p);
	}

	sort(fix.begin(), fix.end());

	int cnt = 0;
	for (auto f : fix)
	{
		if (pipe[f] == false) {
			for (int i = 0; i < L; i++) {
				pipe[f + i] = true;
			}
			cnt++;
		}
	}
	cout << cnt;
}