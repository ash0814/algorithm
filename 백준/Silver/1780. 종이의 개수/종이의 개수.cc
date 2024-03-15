#include <iostream>
#include <vector>

using namespace std;

int paper[2188][2188] = {
		0,
};
int N;
int mone = 0;
int zero = 0;
int one = 0;

bool check(int si, int sj, int n)
{
	int cur = paper[si][sj];
	for (int i = si; i < si + n; i++)
	{
		for (int j = sj; j < sj + n; j++)
		{
			if (paper[i][j] != cur)
				return false;
		}
	}
	if (cur == -1)
		mone++;
	else if (cur == 0)
		zero++;
	else
		one++;
	return true;
}

void recursion(int si, int sj, int n)
{
	if (check(si, sj, n) == true)
		return;
	int size = n / 3;
	recursion(si, sj, size);
	recursion(si, sj + size, size);
	recursion(si, sj + size * 2, size);
	recursion(si + size, sj, size);
	recursion(si + size, sj + size, size);
	recursion(si + size, sj + size * 2, size);
	recursion(si + size * 2, sj, size);
	recursion(si + size * 2, sj + size, size);
	recursion(si + size * 2, sj + size * 2, size);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}

	recursion(0, 0, N);

	cout << mone << "\n"
			 << zero << "\n"
			 << one << "\n";
}