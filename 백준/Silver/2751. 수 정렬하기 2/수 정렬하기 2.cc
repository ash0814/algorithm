#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  vector<int> vec;
  while (N--)
  {
    int num;
    cin >> num;
    vec.push_back(num);
  }
  sort(vec.begin(), vec.end());
  for (auto k : vec)
    cout << k << '\n';

  return 0;
}