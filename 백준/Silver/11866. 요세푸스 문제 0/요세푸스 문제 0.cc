#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  queue<int> q;
  for (int i = 0; i < N; i++)
    q.push(i + 1);

  cout << "<";

  while (!q.empty())
  {
    for (int i = 1; i < K; i++)
    {
      q.push(q.front());
      q.pop();
    }
    cout << q.front();
    q.pop();
    if (q.empty())
      cout << ">" << endl;
    else
      cout << ", ";
  }
}