#include <iostream>

using namespace std;

const int MAX = 6562;
int N;
char star[MAX][MAX];

void recursion(int i, int j, int size, bool fill)
{
	if (size == 1)
	{
		if (fill)
			star[i][j] = '*';
		else
			star[i][j] = ' ';
		return;
	}

	size = size / 3;

	recursion(i, j, size, fill);
	recursion(i, j + size, size, fill);
	recursion(i, j + size * 2, size, fill);
	recursion(i + size, j, size, fill);
	recursion(i + size, j + size, size, false);
	recursion(i + size, j + size*2, size, fill);
	recursion(i + size*2, j, size, fill);
	recursion(i + size*2, j + size, size, fill);
	recursion(i + size*2, j + size*2, size, fill);
}

int main()
{
	cin >> N;

	recursion(0, 0, N, true);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}