#include <iostream>

using namespace std;

int main()
{
  long long fib[100];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < 100; i++)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int N;
  cin >> N;
  cout << fib[N];
  return 0;
}