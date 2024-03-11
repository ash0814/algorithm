#include <iostream>
#include <vector>

using namespace std;

int paper[130][130] = {0, };
int N;
int blue = 0;
int white = 0;

bool check(int si, int sj, int n)
{
	int cur = paper[si][sj];
	for (int i = si; i < si + n; i++)
	{
		for (int j = sj; j < sj + n; j++) {
			if (paper[i][j] != cur)
				return false;
		}
	}
	if (cur == 1)
		blue++;
	else
		white++;
	return true;
}

void recursion(int si, int sj, int n)
{
	if (check(si, sj, n) == true)
		return;
	recursion(si, sj, n/2);
	recursion(si + n/2, sj, n/2);
	recursion(si, sj + n/2, n/2);
	recursion(si + n/2, sj + n/2, n/2);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	recursion(0, 0, N);

	cout << white << "\n" << blue << "\n";
}