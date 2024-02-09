#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
  long long r = a % b;

  while (r != 0)
  {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    vector<int> list;
    for (int i = 0; i < N; i++)
    {
      int num;
      cin >> num;
      list.push_back(num);
    }
    sort(list.begin(), list.end());
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = i + 1; j < N; j++)
      {
        sum += gcd(list[i], list[j]);
      }
    }
    cout << sum << '\n';
  }
}