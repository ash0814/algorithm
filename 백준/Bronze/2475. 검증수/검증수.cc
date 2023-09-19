#include <iostream>
using namespace std;
int main()
{
  int result = 0;
  for (int i = 0; i < 5; i++)
  {
    int n;
    cin >> n;
    result += n * n;
  }
  cout << result % 10 << endl;
  return 0;
}