#include <iostream>
#include <vector>

using namespace std;

int MAX = 10100000;

int main()
{
  int N;
  cin >> N;

  vector<int> a;
  vector<int> b;
  int level = 1;
  int idx = 1;
  while (1)
  {
    if (idx > N || idx > MAX)
      break;
    if (level % 2 == 0)
    {
      for (int i = 1; i <= level; i++)
      {
        a.push_back(i);
        b.push_back(level + 1 - i);
        idx++;
      }
    }
    else
    {
      for (int i = 1; i <= level; i++)
      {
        b.push_back(i);
        a.push_back(level + 1 - i);
        idx++;
      }
    }
    level++;
  }

  cout << a[N - 1] << "/" << b[N - 1] << endl;
  return 0;
}