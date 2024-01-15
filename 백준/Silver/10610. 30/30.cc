#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> numbers;
  string str;
  int zero_cnt = 0;
  int sum = 0;

  cin >> str;
  for (int i = 0; i < str.length(); i++)
  {
    int num = str[i] - '0';
    if (num == 0)
      zero_cnt++;
    numbers.push_back(num);
    sum += num;
  }
  sort(numbers.begin(), numbers.end(), greater<int>());

  if (zero_cnt == 0 || sum % 3 != 0 || zero_cnt == numbers.size())
  {
    cout << -1;
    return 0;
  }

  for (auto n : numbers)
    cout << n;

  return 0;
}