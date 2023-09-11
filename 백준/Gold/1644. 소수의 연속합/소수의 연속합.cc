#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int list[n + 1];
  int res = 0;

  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i <= n; i++)
    list[i] = i;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (list[i] == 0)
      continue;
    for (int j = i * i; j <= n; j += i)
      list[j] = 0;
  }
  vector<int> prime;
  for (int i = 2; i <= n; i++)
  {
    if (list[i] != 0)
      prime.push_back(list[i]);
  }

  int start = 0;
  int end = 0;
  int sum = prime[start];
  while (start <= end && end <= prime.size())
  {
    if (sum == n)
    {
      res++;
      sum -= prime[start];
      start++;
    }
    else if (sum > n)
    {
      sum -= prime[start];
      start++;
    }
    else
    {
      end++;
      sum += prime[end];
    }
    // cout << "sum: " << sum << " (start, end) = (" << start << " , " << end << ")" << endl;
  }
  cout << res << endl;

  return 0;
}