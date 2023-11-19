#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  pair<int, int> list[51];
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> list[i].first >> list[i].second;

  for (int i = 0; i < N; i++)
  {
    int rank = 1;
    for (int j = 0; j < N; j++)
    {
      if (list[i].first < list[j].first && list[i].second < list[j].second)
        rank++;
    }
    cout << rank << " ";
  }
  return 0;
}