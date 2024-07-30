#include <iostream>

using namespace std;

long long B;
int N, mod = 1000;
int A[6][6], result[6][6], tmp[6][6];

void matrix_power(int B[][6]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				tmp[i][j] += (A[i][k] * B[k][j]) % mod;
				tmp[i][j] %= mod;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[i][j] = tmp[i][j];
			tmp[i][j] = 0;
		}
	}
}

void solution()
{
	B--;
	while (B > 0) {
		if (B % 2 == 1)
			matrix_power(result);
		matrix_power(A);

		B /= 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
			A[i][j] %= mod;
			result[i][j] = A[i][j];
		}
	}

	solution();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << result[i][j] << " ";
		cout << '\n';
	}
	return 0;
}