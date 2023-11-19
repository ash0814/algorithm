#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  vector<int> list;

  for (int i = 666; i <= 6660000; i++)
  {
    if (to_string(i).find("666") != string::npos)
      list.push_back(i);
  }
  int N;
  cin >> N;

  cout << list[N - 1] << endl;
  return 0;
}