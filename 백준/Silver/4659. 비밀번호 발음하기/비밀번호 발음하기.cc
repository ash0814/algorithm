#include <iostream>
#include <string>

using namespace std;

string vow = "aeiou";
int has_vow(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (vow.find(str[i]) != string::npos)
      return 1;
  }
  return 0;
}

int check_three(string str)
{
  if (str.length() >= 3)
  {
    for (int i = 0; i < str.length() - 2; i++)
    {
      string check = str.substr(i, 3);
      if (vow.find(check[0]) != string::npos && vow.find(check[1]) != string::npos && vow.find(check[2]) != string::npos)
        return false;
      if (vow.find(check[0]) == string::npos && vow.find(check[1]) == string::npos && vow.find(check[2]) == string::npos)
        return false;
    }
  }
  else
  {
    return true;
  }
  return true;
}

int check_two(string str)
{
  if (str.length() < 2)
  {
    return true;
  }
  else
  {
    for (int i = 0; i < str.length() - 1; i++)
    {
      if (str[i] == str[i + 1])
      {
        if (str[i] == 'e' || str[i] == 'o')
          continue;
        else
          return false;
      }
    }
  }
  return true;
}

int main()
{

  while (1)
  {
    string str;
    cin >> str;
    if (str == "end")
      break;
    int is_acceptable = has_vow(str) && check_three(str) && check_two(str);
    if (is_acceptable)
      cout << "<" << str << "> is acceptable." << endl;
    else
      cout << "<" << str << "> is not acceptable." << endl;
  }
}