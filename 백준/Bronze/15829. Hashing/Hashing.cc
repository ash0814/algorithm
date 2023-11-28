#include <iostream>
#include <string>
#include <map>
#include <math.h>
using namespace std;

int main()
{
  int L;
  cin >> L;
  string str;
  cin >> str;
  map<char, int> alpha;
  for (int i = 0; i < 26; i++)
    alpha.insert({'a' + i, i + 1});

  unsigned long long ans = 0;
  unsigned long long r = 1;
  for (int i = 0; i < L; i++)
  {
    int num = alpha[str[i]];
    ans = (ans + (num * r)) % 1234567891;
    r = (r * 31) % 1234567891;
  }
  cout << ans << endl;
}