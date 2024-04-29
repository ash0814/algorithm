#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;
	deque<int> dq;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int cnt = 0;
	while (M--)
	{
		int num;
		cin >> num;

		int idx = 0;
		while (dq[idx] != num)
			idx++;

		if (idx < dq.size() - idx)
		{
			for (int i = 0; i < idx; i++) {
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				cnt++;
			}
		} else {
			for (int i = 0; i < dq.size() - idx; i++) {
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				cnt++;
			}
		}

		dq.pop_front();
	}
	cout << cnt;
}