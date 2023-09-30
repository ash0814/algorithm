#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sum(string a, string b) // a 가 b보다 큼
{
  string ret = "";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  while (b.length() < a.length())
    b += "0";

  int plus = 0;
  for (int i = 0; i < a.length(); i++)
  {
    int num = a[i] - '0' + b[i] - '0' + plus;
    if (num >= 10)
    {
      plus = 1;
      num -= 10;
    }
    else
    {
      plus = 0;
    }
    ret += num + '0';
  }
  if (plus == 1)
    ret += '1';
  reverse(ret.begin(), ret.end());
  return ret;
}

int main()
{
  int n;
  cin >> n;

  string dp[10001];
  dp[0] = "0";
  dp[1] = "1";

  for (int i = 2; i < 10001; i++)
  {
    dp[i] = sum(dp[i - 1], dp[i - 2]);
  }

  cout << dp[n] << endl;
  return 0;
}