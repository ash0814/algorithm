#include <iostream>
using namespace std;

int main()
{
  int h, m, t;
  cin >> h >> m;
  cin >> t;

  int hour = t / 60;
  int minutes = t % 60;
  int res_h = h + hour;
  int res_m = m + minutes;
  int plus = 0;
  while (res_m >= 60)
  {
    res_m -= 60;
    plus++;
  }
  res_h += plus;
  while (res_h >= 24)
  {
    res_h -= 24;
  }

  cout << res_h << " " << res_m << endl;
  return 0;
}
