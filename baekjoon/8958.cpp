#include <iostream>
#include <cstring>

int main()
{
  int n;
  std::cin >> n;
  char list[n][80];
  int res[n];

  for (int i = 0; i < n; i++)
  {
    int before = 0;
    std::cin >> list[i];
    res[i] = 0;
    for (int j = 0; j < strlen(list[i]); j++)
    {
      if (list[i][j] == 'X')
      {
        for (int k = 1; k <= before; k++)
          res[i] += k;
        before = 0;
      }
      else
      {
        before++;
      }
    }
    if (before > 0)
      for (int k = 1; k <= before; k++)
        res[i] += k;
  }
  for (int i = 0; i < n; i++)
  {
    std::cout << res[i] << std::endl;
  }
}
