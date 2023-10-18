#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  cin >> str;
  int i = 0;
  int j = str.length() - 1;
  while (i <= j)
  {
    if (str[i] == str[j])
    {
      i++;
      j--;
    }
    else
    {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}