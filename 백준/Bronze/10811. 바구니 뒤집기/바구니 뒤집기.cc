#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  vector<int> list;
  for (int i = 1; i <= N; i++)
    list.push_back(i);
  while (M--)
  {
    int i, j;
    cin >> i >> j;
    vector<int> tmp;
    i--;
    j--;
    for (int idx = 0; idx < i; idx++)
      tmp.push_back(list[idx]);
    for (int idx = j; idx >= i; idx--)
      tmp.push_back(list[idx]);
    for (int idx = j + 1; idx < N; idx++)
      tmp.push_back(list[idx]);
    list.clear();

    list = tmp;
  }

  for (auto num : list)
    cout << num << " ";

  return 0;
}