#include <iostream>
#include <stack>

using namespace std;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  stack<int> st;

  int N;
  cin >> N;

  while (N--)
  {
    int command;
    cin >> command;

    if (command == 1)
    {
      int X;
      cin >> X;
      st.push(X);
    }
    else if (command == 2)
    {
      if (!st.empty())
      {
        cout << st.top() << '\n';
        st.pop();
      }
      else
        cout << -1 << '\n';
    }
    else if (command == 3)
      cout << st.size() << '\n';
    else if (command == 4)
      cout << (st.empty() ? 1 : 0) << '\n';
    else if (command == 5)
    {
      if (!st.empty())
        cout << st.top() << '\n';
      else
        cout << -1 << '\n';
    }
    else
      cout << 'error' << '\n';
  }

  return 0;
}