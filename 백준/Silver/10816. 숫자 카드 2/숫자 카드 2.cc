#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, M;
  unordered_map<int, int> umap;
  vector<int> answer;

  cin >> N;
  while (N--)
  {
    int num;
    cin >> num;
    umap[num]++;
  }
  cin >> M;
  while (M--)
  {
    int num;
    cin >> num;
    if (umap[num] >= 1)
      answer.push_back(umap[num]);
    else
      answer.push_back(0);
  }

  for (auto ans : answer)
  {
    cout << ans << " ";
  }
}