#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> ans;

  for (int i = 0; i < N / 2; i++)
  {
    ans.push_back(1);
    ans.push_back(2);
  }
  if (N % 2 == 1)
    ans.push_back(3);

  for (auto n : ans)
    cout << n << " ";

  return 0;
}