#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, b;
  cin >> n >> m >> b;
  int land[501][501] = {
      0,
  };
  int min = 256;
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> land[i][j];
      if (land[i][j] < min)
        min = land[i][j];
      if (land[i][j] > max)
        max = land[i][j];
    }
  }

  map<int, int> res; // time, high
  for (int h = min; h <= max; h++)
  {
    int t = 0;
    int invent = b;
    int cur[501][501];
    copy(&land[0][0], &land[0][0] + 251001, &cur[0][0]);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        while (cur[i][j] < h)
        {
          invent--;
          t++;
          cur[i][j]++;
        }
        while (cur[i][j] > h)
        {
          t += 2;
          cur[i][j]--;
          invent++;
        }
      }
    }
    if (invent >= 0)
    {
      if (res.find(t) != res.end() && res[t] < h)
        res[t] = h;
      else if (res.find(t) == res.end())
        res.insert({t, h});
    }
  }

  cout << res.begin()->first << " " << res.begin()->second << "\n";
  return 0;
}