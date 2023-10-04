#include <iostream>
#include <stack>

using namespace std;

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  stack<pair<int, int>> hit_tower;

  cin >> N;
  int max = -1;
  for (int i = 1; i <= N; i++)
  {
    int t;
    cin >> t;

    while (!hit_tower.empty())
    {
      if (hit_tower.top().first > t)
      {
        cout << hit_tower.top().second << " ";
        break;
      }
      hit_tower.pop();
    }
    if (hit_tower.empty())
      cout << 0 << " ";
    hit_tower.push({t, i});
  }

  return 0;
}