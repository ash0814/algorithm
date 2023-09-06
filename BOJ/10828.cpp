#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  int N;
  stack<int> st;

  cin >> N;
  while (N--)
  {
    string cmd;
    cin >> cmd;
    if (cmd == "push")
    {
      int num;
      cin >> num;
      st.push(num);
    }
    else if (cmd == "top")
    {
      if (st.size() <= 0)
        cout << -1 << endl;
      else
        cout << st.top() << endl;
    }
    else if (cmd == "size")
    {
      cout << st.size() << endl;
    }
    else if (cmd == "pop")
    {
      if (st.size() <= 0)
      {
        cout << -1 << endl;
      }
      else
      {
        cout << st.top() << endl;
        st.pop();
      }
    }
    else if (cmd == "empty")
    {
      cout << st.empty() << endl;
    }
    else
    {
      cout << "error" << endl;
    }
  }
}