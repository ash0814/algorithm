#include <iostream>

using namespace std;

int main()
{
	int D, K;
	cin >> D >> K;
	int fibA[31];
	int fibB[31];

	fibA[0] = 0;
	fibA[1] = 1;
	fibA[2] = 0;
	fibA[3] = 1;

	fibB[0] = 0;
	fibB[1] = 0;
	fibB[2] = 1;
	fibB[3] = 1;


	for (int i = 4; i <= 30; i++) {
		fibA[i] = fibA[i - 1] + fibA[i - 2];
		fibB[i] = fibB[i-1] + fibB[i-2];
	}

	int a = 1;
	int b = 100000;
	while (a <= b) {
		int sum = fibA[D] * a + fibB[D] * b;
		if (sum == K) {
			cout << a << "\n" << b;
			break;
		}

		if (sum < K) {
			a++;
		} else {
			b--;
		}
	}

	return 0;
}