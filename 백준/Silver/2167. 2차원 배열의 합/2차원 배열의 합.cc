#include <iostream>

using namespace std;

int main()
{
	int arr[301][301] = {0, };
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int K;
	cin >> K;
	while (K--)
	{
		int i, j, x, y;
		int sum = 0;
		cin >> i >> j >> x >> y;
		for (int row = i - 1; row < x; row++) {
			for (int col = j - 1; col < y; col++) {
				sum += arr[row][col];
			}
		}
		cout << sum << "\n";
	}
}