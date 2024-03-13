#include <iostream>
#include <cmath>

using namespace std;

int cnt = 0;
int n, r, c;

void recursion(int i, int j, int size)
{
	if (r == j && c == i)
	{
		cout << cnt;
		return;
	}
	else if (c < i + size && r < j + size && c >= i && r >= j)
	{
		recursion(i, j, size / 2);
		recursion(i + (size / 2), j, size / 2);
		recursion(i, j + (size / 2), size / 2);
		recursion(i + (size / 2), j + (size / 2), size / 2);
	}
	else
	{
		cnt += size * size;
	}
}

int main()
{
	cin >> n >> r >> c;

	int size = pow(2, n);

	recursion(0, 0, size);
}