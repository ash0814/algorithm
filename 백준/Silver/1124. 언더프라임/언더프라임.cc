#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int prime[100000] = {0, };

bool is_underprime(int num)
{
	int primeCnt = 0;
	for (int i = 2; i * i <= num; i++) {
		while (num % i == 0) {
			primeCnt++;
			num /= i;
		}
	}
	if (num > 1)
		primeCnt++;
	if (prime[primeCnt] != 0)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 2; i <= 100000; i++) {
		prime[i] = i;
	}

	for (int i = 2; i <= 317; i++) {
		if (prime[i] == 0)
			continue;
		for (int j = i * i; j <= 100000; j += i) {
			prime[j] = 0;
		}
	}

	int A, B;
	cin >> A >> B;
	int cnt = 0;

	for (int num = A; num <= B; num++) {
		if (is_underprime(num))
			cnt++;
	}

	cout << cnt;


}