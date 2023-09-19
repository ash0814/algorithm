#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  cin >> str;
  int how[27] = {
      0,
  };
  for (int i = 0; i < str.length(); i++)
  {
    int alpa_num = (int)str[i] > 90 ? (int)str[i] - 32 : (int)str[i];
    how[alpa_num - 65]++;
  }
  int max = 0;
  for (int i = 0; i < 26; i++)
  {
    if (how[max] < how[i])
      max = i;
  }
  char result = (char)(max + 65);
  for (int i = 0; i < 26; i++)
  {
    if (how[max] == how[i] && max != i)
    {
      result = '?';
      break;
    }
  }
  cout << result << endl;
  return 0;
}
