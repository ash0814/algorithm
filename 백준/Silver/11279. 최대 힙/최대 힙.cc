#include <iostream>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  priority_queue<int> pq;
  while (N--)
  {
    int num;
    cin >> num;
    if (num == 0)
    {
      if (pq.empty())
        cout << 0 << "\n";
      else
      {
        cout << pq.top() << "\n";
        pq.pop();
      }
    }
    else
    {
      pq.push(num);
    }
  }
}