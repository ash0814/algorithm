#include <iostream>
#include <string>
#include <stack>
using namespace std;

int isBalance(string str)
{
  stack<char> stk;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(' || str[i] == '[')
    {
      stk.push(str[i]);
    }
    else if (str[i] == ')' || str[i] == ']')
    {
      if (stk.size() <= 0)
        return 0;
      if (str[i] == ')' && stk.top() == '(')
        stk.pop();
      else if (str[i] == ']' && stk.top() == '[')
        stk.pop();
      else
        return 0;
    }
  }
  if (stk.size() > 0)
    return 0;
  return 1;
}

int main()
{
  string str;
  getline(cin, str);
  while (!(str == "." && str.length() == 1))
  {
    string res = isBalance(str) ? "yes" : "no";
    cout << res << endl;
    getline(cin, str);
  }
  return 0;
}