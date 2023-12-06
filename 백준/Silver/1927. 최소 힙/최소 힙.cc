#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> N;
  while (N--)
  {
    unsigned int num;
    cin >> num;
    if (num == 0)
    {
      if (pq.empty())
      {
        cout << 0 << '\n';
      }
      else
      {
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else
    {
      pq.push(num);
    }
  }
  return 0;
}