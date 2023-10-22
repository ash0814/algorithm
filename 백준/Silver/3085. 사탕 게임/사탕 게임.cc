#include <iostream>
#include <algorithm>

using namespace std;
int n;
char candy[51][51];

int find_longest()
{
  int longest = 0;
  for (int i = 0; i < n; i++)
  {
    int row = 0;
    char r_now = candy[i][0];
    for (int j = 0; j < n; j++)
    {
      if (candy[i][j] == r_now)
        row++;
      else
      {
        longest = row > longest ? row : longest;
        row = 1;
        r_now = candy[i][j];
      }
    }
    longest = max(row, longest);
  }
  for (int i = 0; i < n; i++)
  {
    int col = 0;
    char now = candy[0][i];
    for (int j = 0; j < n; j++)
    {
      if (candy[j][i] == now)
        col++;
      else
      {
        longest = col > longest ? col : longest;
        col = 1;
        now = candy[j][i];
      }
    }
    longest = max(col, longest);
  }
  return longest;
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> candy[i][j];

  int answer = find_longest();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      // cout << "{" << i << ", " << j << "} <=> {" << i << ", " << j + 1 << "}" << endl;
      char tmp = candy[i][j];
      candy[i][j] = candy[i][j + 1];
      candy[i][j + 1] = tmp;
      answer = max(find_longest(), answer);
      tmp = candy[i][j];
      candy[i][j] = candy[i][j + 1];
      candy[i][j + 1] = tmp;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      char tmp = candy[j][i];
      candy[j][i] = candy[j + 1][i];
      candy[j + 1][i] = tmp;
      answer = max(find_longest(), answer);
      tmp = candy[j][i];
      candy[j][i] = candy[j + 1][i];
      candy[j + 1][i] = tmp;
    }
  }

  cout << answer << endl;
  return 0;
}