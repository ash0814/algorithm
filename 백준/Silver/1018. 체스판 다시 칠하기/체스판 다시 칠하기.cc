#include <iostream>
#include <vector>
#include <string>

using namespace std;

string chessMap[50];
string BStart[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};
string WStart[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

int get_wcount(int x, int y)
{
  int cnt = 0;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (chessMap[x + i][y + j] != WStart[i][j])
        cnt++;
    }
  }
  return cnt;
}

int get_bcount(int x, int y)
{

  int cnt = 0;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (chessMap[x + i][y + j] != BStart[i][j])
        cnt++;
    }
  }
  return cnt;
}

int main()
{
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> chessMap[i];
  int res = 2147483647;
  for (int i = 0; i + 8 <= N; i++)
  {
    for (int j = 0; j + 8 <= M; j++)
    {
      int tmp;
      tmp = min(get_wcount(i, j), get_bcount(i, j));
      if (tmp < res)
        res = tmp;
    }
  }
  cout << res << endl;
  return 0;
}