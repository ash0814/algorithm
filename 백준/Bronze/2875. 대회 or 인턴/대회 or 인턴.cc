#include <iostream>

using namespace std;

int main()
{
  int N, M, K;
  cin >> N >> M >> K;
  int left = N + M;
  int team = 0;
  while (left >= K)
  {
    N -= 2;
    M -= 1;
    left -= 3;
    if (N < 0 || M < 0 || left < K)
      break;
    team++;
  }
  cout << team << endl;
}