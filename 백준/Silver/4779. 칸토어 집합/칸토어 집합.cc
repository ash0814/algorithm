#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX = 531442;

char list[MAX];

void solution(int idx, int num, bool fill)
{
	if (num == 1) {
		if (fill)
			list[idx] = '-';
		else
			list[idx] = ' ';
		return;
	}

	solution(idx, num / 3, fill);
	solution(idx + (num / 3), num / 3, false);
	solution(idx + 2 * (num / 3), num / 3, fill);
}

int main()
{
	while (true)
	{
		int N;
		cin >> N;
		if (cin.eof())
			break;
		memset(list, ' ', sizeof(list));
		int num = pow(3, N);
		solution(0, num, true);
		for (int i = 0; i < num; i++) {
			cout << list[i];
		}
		cout << '\n';
	}
}