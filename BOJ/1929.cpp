#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

int main()
{
  int m, n;
  std::cin >> m >> n;
  int list[n];
  int cnt;

  for (int i = 0; i <= n; i++)
    list[i] = i;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (list[i] == 0)
      continue;
    for (int j = i * i; j <= n; j += i)
      list[j] = 0;
  }
  for (int i = m; i <= n; i++)
    if (list[i] != 0 && list[i] != 1)
      std::cout << list[i] << "\n";
}