#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int BLACK = 1;
const int WHITE = 2;

int board[20][20] = {
		0,
};
int dx[8] = {0, -1, 1, 1, 0, 1, -1, -1};
int dy[8] = {1, 1, 0, 1, -1, -1, 0, -1};
int cnt = 0;

vector<int> check_dir(int x, int y, int color)
{
	vector<int> res;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
			continue;
		if (board[nx][ny] == color)
			res.push_back(i);
	}
	return res;
}

void check_line(int i, int j, int color, int dir)
{
	int rdir = dir + 4;
	int ni = i + dx[rdir];
	int nj = j + dy[rdir];
	if (ni < 0 || ni >= 19 || nj < 0 || nj >= 19)
		;
	else if (board[ni][nj] == color)
		return;
	while (board[i][j] == color)
	{
		i += dx[dir];
		j += dy[dir];
		if (i < 0 || i >= 19 || j < 0 || j >= 19 || board[i][j] != color)
			break;
		cnt++;
	}
}

int main()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] != 0)
			{
				vector<int> dirList = check_dir(i, j, board[i][j]);

				for (auto dir : dirList)
				{
					cnt = 1;
					check_line(i, j, board[i][j], dir);
					if (cnt == 5)
					{
						cout << board[i][j] << "\n";
						cout << i + 1 << " " << j + 1 << "\n";
						return 0;
					}
				}
			}
		}
	}
	cout << 0 << endl;
}
