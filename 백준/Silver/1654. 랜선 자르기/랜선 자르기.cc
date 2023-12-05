#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long K, N;
  vector<long long> list;
  cin >> K >> N;
  long long min = INT16_MAX + 1;
  long long max = -1;
  while (K--)
  {
    long long num;
    cin >> num;
    list.push_back(num);
    if (num < min)
      min = num;
    if (num > max)
      max = num;
  }
  long long start = min / N;
  long long end = max;
  int ans;
  while (start <= end)
  {
    long long mid = (start + end) / 2;
    long long sum = 0;
    if (start == end)
    {
      for (int i = 0; i < list.size(); i++)
        sum += (list[i] / mid);
      if (sum >= N)
        ans = mid;
      else
        ans = mid - 1;
      break;
    }

    for (int i = 0; i < list.size(); i++)
      sum += (list[i] / mid);
    if (sum >= N)
      start = mid + 1;
    else
      end = mid;
  }
  cout << ans;
}