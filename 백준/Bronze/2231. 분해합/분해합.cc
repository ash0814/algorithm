#include <iostream>

using namespace std;

long long decomposition(int i)
{
  int sum = i;
  while (i > 10)
  {
    sum += i % 10;
    i /= 10;
  }
  sum += i;
  return sum;
}

int main()
{
  int N;
  cin >> N;

  for (int i = 1; i < N; i++)
  {
    if (decomposition(i) == N)
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}