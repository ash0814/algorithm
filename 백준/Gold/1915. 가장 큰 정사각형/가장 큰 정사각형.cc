#include <iostream>
#include <vector>

using namespace std;

int min_3(int a, int b, int c)
{
  if (a <= b && a <= c)
    return a;
  if (b <= a && b <= c)
    return b;
  return c;
}

int main()
{
  int N, M;
  cin >> N >> M;
  int board[1001][1001] = {
      0,
  };
  int zero = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      char c;
      cin >> c;
      board[i][j] = c - '0';
      if (c == '1')
        zero = 1;
    }
  }

  if (zero == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  int answer = 1;
  for (int i = 1; i < N; i++)
  {
    for (int j = 1; j < M; j++)
    {
      if (board[i][j] == 0)
        board[i][j] = 0;
      else
      {
        board[i][j] = min_3(board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]) + 1;
        answer = answer < board[i][j] ? board[i][j] : answer;
      }
    }
  }

  cout << answer * answer << endl;
  return 0;
}