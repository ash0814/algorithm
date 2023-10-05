#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
  deque<int> dq;
  int N;
  cin >> N;
  while (N--)
  {
    string cmd;
    cin >> cmd;

    int n;
    if (cmd == "push_front")
    {
      cin >> n;
      dq.push_front(n);
    }
    else if (cmd == "push_back")
    {
      cin >> n;
      dq.push_back(n);
    }
    else if (cmd == "pop_back")
    {
      if (dq.empty())
        cout << -1 << endl;
      else
      {
        cout << dq.back() << endl;
        dq.pop_back();
      }
    }
    else if (cmd == "pop_front")
    {
      if (dq.empty())
        cout << -1 << endl;
      else
      {
        cout << dq.front() << endl;
        dq.pop_front();
      }
    }
    else if (cmd == "size")
      cout << dq.size() << endl;
    else if (cmd == "empty")
      cout << dq.empty() << endl;
    else if (cmd == "front")
    {
      if (dq.empty())
        cout << -1 << endl;
      else
        cout << dq.front() << endl;
    }
    else if (cmd == "back")
    {
      if (dq.empty())
        cout << -1 << endl;
      else
        cout << dq.back() << endl;
    }
  }

  return 0;
}