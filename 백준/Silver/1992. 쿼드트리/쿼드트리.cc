#include <iostream>

using namespace std;

int map[80][80] = {0, };
string res = "";

bool check(int i, int j, int size)
{
	int cur = map[i][j];
	for (int x = i; x < i + size; x++) {
		for (int y = j; y < j + size; y++) {
			if (map[x][y] != cur)
				return false;
		}
	}
	return true;
}

void solution(int i, int j, int size)
{
	if (check(i, j, size) == true) {
		res += map[i][j] + '0';
		return ;
	} else {
		res += '(';
		solution(i, j, size / 2);
		solution(i, j + size / 2, size / 2);
		solution(i + size / 2, j, size / 2);
		solution(i + size / 2, j + size / 2, size / 2);
	}
	res += ')';
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	solution(0, 0, N);

	cout << res << endl;
}