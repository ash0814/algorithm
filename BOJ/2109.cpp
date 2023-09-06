#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
  int N;
  cin >> N;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for (int i = 0; i < N; i++)
  {
    int p, d;
    cin >> p >> d;
    pq.push({d, p});
  }

  priority_queue<int, vector<int>, greater<int>> heap;
  while (!pq.empty())
  {
    heap.push(pq.top().second);
    if (heap.size() > pq.top().first)
      heap.pop();
    pq.pop();
  }

  int ret = 0;
  while (!heap.empty())
  {
    ret += heap.top();
    heap.pop();
  }

  cout << ret << endl;

  return 0;
}