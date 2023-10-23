#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (isspace(str[i]))
      continue;
    else if (str[i] == 'c' && i + 1 < str.length() && (str[i + 1] == '=' || str[i + 1] == '-'))
    {
      cnt++;
      i++;
    }
    else if ((str[i] == 's' || str[i] == 'z') && i + 1 < str.length() && str[i + 1] == '=')
    {
      cnt++;
      i++;
    }
    else if (str[i] == 'd')
    {
      if (i + 1 < str.length() && str[i + 1] == '-')
      {
        cnt++;
        i++;
      }
      else if (i + 2 < str.length() && str[i + 1] == 'z' && str[i + 2] == '=')
      {
        cnt++;
        i += 2;
      }
      else
      {
        cnt++;
      }
    }
    else if ((str[i] == 'l' || str[i] == 'n') && i + 1 < str.length() && str[i + 1] == 'j')
    {
      cnt++;
      i++;
    }
    else
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}