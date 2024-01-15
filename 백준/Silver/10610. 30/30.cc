#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> numbers;
  string str;
  int zero_cnt = 0;
  int one = 0;
  int two = 0;

  cin >> str;
  for (int i = 0; i < str.length(); i++)
  {
    // 0 아닐때만 numbers에 넣기
    int num = str[i] - '0';
    if (num == 0)
      zero_cnt++;
    numbers.push_back(num);
    if (num % 3 == 1)
      one++;
    else if (num % 3 == 2)
      two++;
  }

  one %= 3;
  two %= 3;
  sort(numbers.begin(), numbers.end(), greater<int>());

  if (zero_cnt == 0 || zero_cnt == numbers.size() || one != two)
  {
    cout << -1;
    return 0;
  }

  for (auto n : numbers)
  {
    cout << n;
  }

  return 0;
}