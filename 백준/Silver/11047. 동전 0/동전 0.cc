#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, K;
  vector<int> A;
  cin >> N >> K;
  while (N--)
  {
    int m;
    cin >> m;
    A.push_back(m);
  }

  int res = 0;
  for (int i = A.size() - 1; i >= 0; i--)
  {
    while (K / A[i] > 0)
    {
      res += K / A[i];
      K -= (K / A[i]) * A[i];
    }
  }

  cout << res << endl;
}