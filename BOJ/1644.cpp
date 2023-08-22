#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int list[n];
  int res = 0;

  for (int i = 0; i <= n; i++)
    list[i] = i;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (list[i] == 0)
      continue;
    for (int j = i * i; j <= n; j += i)
      list[j] = 0;
  }

  // for (int i = 0; i <= n; i++)
  //   cout << list[i] << " ";

    return 0;
}