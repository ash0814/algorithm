#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	int list[10001];
	int perm[10001];
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		perm[i] = list[i];
	}

	bool isDone = false;
	bool flag = false;

	do {
		if (flag) {
			for (int i = 0; i < N; i++) {
				cout << perm[i] << " ";
			}
			isDone = true;
			break;
		}

		for (int i = 0; i < N; i++) {
			if (perm[i] == list[i])
				flag = true;
			else {
				flag = false;
				break;
			}
		}
	} while (prev_permutation(perm, perm + N));

	if (!isDone)
		cout << -1;

	return 0;
}