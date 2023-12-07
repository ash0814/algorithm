#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  queue<int> list;
  for (int i = 1; i <= N; i++)
    list.push(i);
  cout << "<";
  while (list.size() > 1)
  {
    for (int i = 0; i < K - 1; i++)
    {
      list.push(list.front());
      list.pop();
    }
    cout << list.front() << ", ";
    list.pop();
  }
  cout << list.front() << ">" << endl;
}