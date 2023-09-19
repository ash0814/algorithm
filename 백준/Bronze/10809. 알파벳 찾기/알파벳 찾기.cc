#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
  int list[26];
  memset(list, -1, sizeof(list));
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++)
  {
    if (list[str[i] - 97] == -1)
      list[str[i] - 97] = i;
  }

  for (int i = 0; i < 26; i++)
    cout << list[i] << " ";
  return 0;
}