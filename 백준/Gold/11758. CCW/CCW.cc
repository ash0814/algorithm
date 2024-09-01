#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  pair<int, int> p[3];

  for (int i = 0; i < 3; i++)
  {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }
  int ccw = (p[1].first - p[0].first) * (p[2].second - p[0].second) - (p[1].second - p[0].second) * (p[2].first - p[0].first);
  if (ccw > 0)
    cout << 1;
  else if (ccw < 0)
    cout << -1;
  else
    cout << 0;
}