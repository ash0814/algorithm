#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
  string input;
  cin >> input;
  vector<int> numbers;
  vector<char> sign;
  string term = "";
  int minIndex = -1;

  for (int i = 0; i < input.length(); i++)
  {
    if ('0' <= input[i] && input[i] <= '9')
      term += input[i];
    else
    {
      numbers.push_back(stoi(term));
      term = "";
      if (input[i] == '-' && minIndex == -1)
        minIndex = numbers.size();
    }
  }
  numbers.push_back(stoi(term));

  int ret = 0;
  if (minIndex == -1)
  {
    for (int i = 0; i < numbers.size(); i++)
      ret += numbers[i];
  }
  else
  {
    for (int i = 0; i < minIndex; i++)
      ret += numbers[i];
    for (int i = minIndex; i < numbers.size(); i++)
      ret -= numbers[i];
  }
  cout << ret << endl;
  return 0;
}