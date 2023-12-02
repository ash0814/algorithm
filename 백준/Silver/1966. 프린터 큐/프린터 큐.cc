#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool findBiggerNumber(queue<pair<int, int>> q, int findNum)
{
  queue<pair<int, int>> tmp = q;
  tmp.pop();
  while (!tmp.empty())
  {
    if (tmp.front().first > findNum)
      return true;
    else
      tmp.pop();
  }
  return false;
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while (T--)
  {
    int N, M;
    cin >> N >> M;
    queue<pair<int, int>> printer;
    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
      int imp;
      cin >> imp;
      printer.push({imp, i});
    }
    while (!printer.empty())
    {
      if (findBiggerNumber(printer, printer.front().first) == true)
      {
        printer.push(printer.front());
        printer.pop();
      }
      else
      {
        if (printer.front().second == M)
        {
          cout << cnt << endl;
          break;
        }
        printer.pop();
        cnt++;
      }
    }
  }
  return 0;
}