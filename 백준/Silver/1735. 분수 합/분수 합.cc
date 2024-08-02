#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int x, int y)
{
  int z = 1;
  while (y != 0)
  {
    z = x % y;
    x = y;
    y = z;
  }
  return x;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int x = A * D + B * C;
  int y = B * D;

  int min = gcd(x, y);
  cout << x / min << ' ' << y / min << '\n';
}