#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int prime[1000001] = {0, };

	for (int i = 2; i <= 1000000; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= 1000; i++) {
		if (prime[i] == 0)
			continue;
		for (int j = i * i; j <= 1000000; j+=i) {
			prime[j] = 0;
		}
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		int cnt = 0;
		cin >> N;

		vector<int> p;
		for (int i = 2; i <= N; i++) {
			if (prime[i] != 0)
				p.push_back(i);
		}

		int left = 0;
		int right = p.size() - 1;

		while (left <= right) {
			int sum = p[left] + p[right];
			if (sum == N) {
				cnt++;
				left++;
				right--;
			} else if (sum < N) {
				left++;
			} else {
				right--;
			}
		}

		cout << cnt << '\n';
	}

}