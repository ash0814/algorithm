#include <iostream>
using namespace std;

int main()
{
  int n;
  long long s = 0;
  cin >> n;
  for (long long i = 1; i <= n - 2; i++)
    s += (i * i + i) / 2;

  cout << s << "\n"
       << "3";

  return 0;
}