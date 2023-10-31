#include <iostream>
using namespace std;

int main()
{
  long fac[11];
  fac[0] = 1;
  for (int i = 1; i <= 10; i++)
    fac[i] = i * fac[i - 1];

  int N, K;
  cin >> N >> K;
  cout << fac[N] / (fac[N - K] * fac[K]) << endl;
  return 0;
}