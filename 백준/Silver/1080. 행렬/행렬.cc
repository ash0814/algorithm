#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[51][51] = {0, };
int B[51][51] = {0, };
int res = 0;

void printA()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j];
		}
		cout << endl;
	}
}

void rev(int x, int y)
{
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			A[i][j] = A[i][j] ? 0 : 1;
		}
	}
	res++;
}

bool check()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j])
				return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			A[i][j] = c - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			B[i][j] = c - '0';
		}
	}

	if (N < 3 || M < 3) {
		if (check()) {
			cout << 0;
		} else {
			cout << -1;
		}
		return 0;
	}

	for (int x = 0; x <= N - 3; x++) {
		for (int y = 0; y <= M - 3; y++) {
			if (A[x][y] != B[x][y])
				rev(x, y);
			if (check()) {
				cout << res;
				return 0;
			}
		}
	}

	cout << -1;
	return 0;
}