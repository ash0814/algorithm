#include <iostream>

using namespace std;

int list[300000];

int solution(int n)
{
	int res = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
		if (list[i] != 0) {
			res++;
		}
	}
	return res;
}

int main()
{
	int n;

	for (int i = 1; i < 300000; i++) {
		list[i] = i;
	}

	for (int i = 2; i < 300000; i++) {
		if (list[i] == 0)
			continue;
		for (int j = 2 * i; j < 300000; j+= i) {
			list[j] = 0;
		}
	}

	cin >> n;
	while (n != 0) {
		cout << solution(n) << "\n";
		cin >> n;
	}
}