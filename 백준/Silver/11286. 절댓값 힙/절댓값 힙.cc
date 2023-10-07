#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int N;
  priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;

  cin >> N;
  while (N--)
  {
    long i;
    cin >> i;
    if (i == 0)
    {
      if (pq.empty())
        cout << 0 << endl;
      else
      {
        cout << pq.top().second << endl;
        pq.pop();
      }
    }
    else
    {
      long abs = i > 0 ? i : -i;
      pq.push({abs, i});
    }
  }

  return 0;
}