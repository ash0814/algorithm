#include <iostream>

using namespace std;

int main()
{
  long long fib[81];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= 80; i++)
    fib[i] = fib[i - 1] + fib[i - 2];

  long long length[81];

  length[0] = 0;
  length[1] = 4;
  for (int i = 0; i <= 80; i++)
  {
    length[i] = fib[i] * 4 + fib[i - 1] * 2;
  }

  int N;
  cin >> N;
  cout << length[N] << endl;

  return 0;
}