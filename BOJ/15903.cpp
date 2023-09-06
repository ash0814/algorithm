#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
  int n, m;
  long long ret = 0;
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    long long tmp;
    cin >> tmp;
    pq.push(tmp);
  }

  for (int i = 0; i < m; i++)
  {
    long long a = pq.top();
    pq.pop();
    long long b = pq.top();
    pq.pop();
    pq.push(a + b);
    pq.push(a + b);
  }

  while (!pq.empty())
  {
    ret += pq.top();
    pq.pop();
  }

  cout << ret << endl;
  return 0;
}