#include <iostream>
#include <string>
using namespace std;

int main()
{
  string n = "";
  while (true)
  {
    cin >> n;
    if (n == "0")
      return 0;
    int i = 0;
    int j = n.length() - 1;
    string res;
    while (i < j)
    {
      if (n[i] != n[j])
      {
        res = "no";
        break;
      }
      i++;
      j--;
    }
    if (res != "no")
      res = "yes";
    cout << res << endl;
  }
  return 0;
}