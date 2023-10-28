#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> list;

  while (N--)
  {
    int t;
    cin >> t;
    list.push_back(t);
  }
  sort(list.begin(), list.end());
  int answer = 0;
  for (int i = 0; i < list.size(); i++)
  {
    for (int j = 0; j <= i; j++)
      answer += list[j];
  }
  cout << answer << endl;
  return 0;
}