#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
  int N;
  cin >> N;
  vector<pair<int, int>> vec;

  for (int i = 0; i < N; i++)
  {
    int start, end;
    cin >> start >> end;
    vec.push_back(pair<int, int>(end, start));
  }
  sort(vec.begin(), vec.end());

  int cnt = 1;
  pair<int, int> tmp = vec[0];
  for (int i = 1; i < N; i++)
  {
    if (tmp.first <= vec[i].second)
    {
      cnt++;
      tmp = vec[i];
    }
  }
  cout << cnt << endl;
}