#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int alist[12] = {0, };
int N;
int oper[4] = {0, };
int minRes = 1000000000;
int maxRes = -1000000000;

void bt(int depth, int num)
{
	if (depth == N) {
		minRes = min(minRes, num);
		maxRes = max(maxRes, num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			if (oper[i] > 0) {
				oper[i]--;
				bt(depth+1, num + alist[depth]);
				oper[i]++;
			}
		} else if (i == 1) {
			if (oper[i] > 0) {
				oper[i]--;
				bt(depth+1, num - alist[depth]);
				oper[i]++;
			}
		} else if (i == 2) {
			if (oper[i] > 0) {
				oper[i]--;
				bt(depth + 1, num * alist[depth]);
				oper[i]++;
			}
		} else {
			if (oper[i]>0) {
				oper[i]--;
				bt(depth + 1, num / alist[depth]);
				oper[i]++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> alist[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	bt(1, alist[0]);

	cout << maxRes << "\n" << minRes;
}