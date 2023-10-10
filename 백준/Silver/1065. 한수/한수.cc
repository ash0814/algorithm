#include <iostream>

using namespace std;

int main()
{
  int num;
  cin >> num;
  int answer = 0;
  if (num < 100)
  {
    cout << num << endl;
    return 0;
  }
  else if (num == 1000)
  {
    cout << 144 << endl;
    return 0;
  }

  answer += 99;

  for (int i = 100; i <= num; i++)
  {
    int a, b, c;
    a = i / 100;
    b = (i / 10) % 10;
    c = i % 10;
    if (a + c == 2 * b)
      answer++;
  }

  cout << answer << endl;
  return 0;
}