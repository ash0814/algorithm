#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int buildings[1001] = {0, };;
	int max_pos, max_h = 0;

	for (int i = 0; i < N; i++)
	{
		int L, H;
		cin >> L >> H;
		buildings[L] = H;
		if (max_h < H)
		{
			max_pos = L;
			max_h = H;
		}
	}

	int res = 0;

	int Lh = 0;
	for (int i = 1; i < max_pos; i++)
	{
		Lh = max(Lh, buildings[i]);
		res += Lh;
	}

	int Rh = 0;
	for (int i = 1000; i > max_pos; i--)
	{
		Rh = max(Rh, buildings[i]);
		res += Rh;
	}

	cout << res + max_h;
}