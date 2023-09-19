#include <iostream>
#include <string>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int H, W, N;
    cin >> H >> W >> N;
    if (N % H == 0)
      cout << H * 100 + N / H << endl;
    else
      cout << (N % H) * 100 + N / H + 1 << endl;
  }
  return 0;
}