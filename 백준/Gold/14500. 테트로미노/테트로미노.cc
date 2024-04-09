#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int map[501][501] = {
		0,
};
int N, M;
set<int> maxSum;

void find_square()
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			int sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
			maxSum.insert(sum);
		}
	}
}

void find_row() // _
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 3; j++)
		{
			int sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			maxSum.insert(sum);
		}
	}
}

void find_col()
{
	for (int i = 0; i < N - 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			maxSum.insert(sum);
		}
	}
}

void find_col_six()
{
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			maxSum.insert(map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1]);
			maxSum.insert(map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			maxSum.insert(map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			maxSum.insert(map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j]);
			maxSum.insert(map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			maxSum.insert(map[i][j] + map[i][j+1] + map[i+1][j] + map[i+2][j]);
			maxSum.insert(map[i+2][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1]);
			maxSum.insert(map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+2][j]);
		}
	}
}

void find_row_six()
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			maxSum.insert(map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j]);
			maxSum.insert(map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			maxSum.insert(map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2]);
			maxSum.insert(map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			maxSum.insert(map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1]);
			maxSum.insert(map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2]);
			maxSum.insert(map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2]);
			maxSum.insert(map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2]);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	find_row();
	find_col();
	find_square();
	find_col_six();
	find_row_six();

	cout << *(maxSum.rbegin());
}