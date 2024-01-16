#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;
  while (N--)
  {
    int c;
    cin >> c;
    int q = c / 25;
    c %= 25;
    int d = c / 10;
    c %= 10;
    int n = c / 5;
    c %= 5;
    cout << q << " " << d << " " << n << " " << c << endl;
  }
}