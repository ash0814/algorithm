#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count2(unsigned int num)
{
  int cnt = 0;
  while (num != 0)
  {
    num /= 2;
    cnt += num;
  }
  return cnt;
}

int count5(unsigned int num)
{
  int cnt = 0;
  while (num != 0)
  {
    num /= 5;
    cnt += num;
  }
  return cnt;
}

int main()
{
  unsigned int n, m;
  cin >> n >> m;

  int res2 = count2(n) - (count2(m) + count2(n - m));
  int res5 = count5(n) - (count5(m) + count5(n - m));
  cout << min(res2, res5);
}