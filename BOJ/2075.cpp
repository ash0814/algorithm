#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int list[N][N];
  priority_queue<int> pq;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int num;
      cin >> num;
      list[i][j] = num;
    }
  }

  return 0;
}