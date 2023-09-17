#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  int N;
  cin >> N;

  while (N--)
  {
    string str;
    stack<char> vps;

    cin >> str;
    int i = -1;
    while (++i < str.length())
    {
      if (str[i] == '(')
        vps.push(str[i]);
      else
      {
        if (vps.empty() == false && vps.top() == '(')
          vps.pop();
        else
          break;
      }
    }
    if (vps.empty() == true && i == str.length())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}