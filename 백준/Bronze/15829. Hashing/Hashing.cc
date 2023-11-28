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

  long long ans = 0;
  for (int i = 0; i < L; i++)
  {
    int num = alpha[str[i]];
    ans += num * powl(31, i);
  }
  cout << ans % 1234567891 << endl;
}