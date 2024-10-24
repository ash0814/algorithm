#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int prime[1001] = {0, };
	for (int i = 2;i <= N; i++) {
		prime[i] = i;
	}

	int cnt = 0;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; i * j <= N; j++) {
			if (prime[i*j] == 0)
				continue;
			prime[i*j] = 0;
			cnt++;
			if (cnt == K) {
				cout << i * j << endl;
				return 0;
			}
		}
	}

}