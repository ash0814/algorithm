#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> list;
  while (N--)
  {
    int n;
    cin >> n;
    list.push_back(n);
  }
  int findNumber;
  cin >> findNumber;
  int answer = 0;
  for (auto n : list)
  {
    if (n == findNumber)
      answer++;
  }
  cout << answer << endl;
  return 0;
}