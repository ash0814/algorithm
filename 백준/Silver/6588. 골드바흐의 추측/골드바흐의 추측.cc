#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int prime[1000001] = {
      0,
  };
  for (int i = 1; i <= 1000000; i++)
    prime[i] = i;

  for (int i = 2; i <= 1000000; i++)
  {
    if (prime[i] == 0)
      continue;
    for (int j = i + i; j <= 1000000; j += i)
      prime[j] = 0;
  }

  while (1)
  {
    int n;
    cin >> n;
    if (n == 0)
      break;

    for (int i = 3; i <= n / 2; i += 2)
    {
      if (prime[i] != 0 && prime[n - i] != 0)
      {
        cout << n << " = " << i << " + " << n - i << '\n';
        break;
      }
    }
  }

  return 0;
}