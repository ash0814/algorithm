#include <iostream>
#include <string>
using namespace std;

int main()
{
  int N;
  cin >> N;
  string num;
  cin >> num;
  int ret = 0;
  for (int i = 0; i < N; i++)
    ret += num[i] - '0';
  cout << ret << endl;
  return 0;
}