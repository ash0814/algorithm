#include <iostream>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int res = 0;
  if (a == b && b == c)
  {
    res = 10000 + (a * 1000);
  }
  else if (a != b && b != c && a != c)
  {
    res = max(a, max(b, c)) * 100;
  }
  else
  {
    if (a == b || a == c)
      res = a * 100 + 1000;
    else if (b == c)
      res = b * 100 + 1000;
  }
  cout << res << endl;
}