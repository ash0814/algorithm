#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  if (T % 10 != 0)
  {
    cout << -1 << endl;
    return 0;
  }
  int A = T / 300;
  T %= 300;
  int B = T / 60;
  T %= 60;
  int C = T / 10;
  cout << A << " " << B << " " << C << endl;
}