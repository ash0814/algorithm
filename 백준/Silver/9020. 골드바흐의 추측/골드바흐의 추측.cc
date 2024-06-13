#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int prime[10001];
	for (int i = 2; i <= 10000; i++)
		prime[i] = i;

	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == 0)
			continue;
		else {
			for (int j = 2 * i; j <= 10000; j += i)
				prime[j] = 0;
		}
	}

	vector<int> list;
	for (int i = 0; i <= 10000; i++) {
		if (prime[i] != 0)
			list.push_back(i);
	}

	while (T--)
	{
		int num;
		cin >> num;

		int start = 0;
		int end = list.size() - 1;

		int res_A, res_B;
		while (start <= end) {
			int sum = list[start] + list[end];

			if (sum >= num) {
				if (sum == num) {
					res_A = list[start];
					res_B = list[end];
				}
				end--;
			} else {
				start++;
			}
		}

		cout << res_A << " " << res_B << "\n";
	}
}