#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	char graph[101][101];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	// row
	int row_cnt = 0;
	for (int i = 0; i < N; i++) {
		int dot = 0;
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == '.') {
				dot++;
			} else {
				if (dot >= 2)
					row_cnt++;
				dot = 0;
			}
		}
		if (dot >= 2)
			row_cnt++;
	}

	// col
	int col_cnt = 0;

	for (int j = 0; j < N; j++) {
		int dot = 0;
		for (int i = 0; i < N; i++) {
			if (graph[i][j] == '.')
				dot++;
			else {
				if (dot >= 2)
					col_cnt++;
				dot = 0;
			}
		}
		if (dot >= 2)
			col_cnt++;
	}

	cout << row_cnt << " " << col_cnt;
}