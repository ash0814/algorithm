#include <iostream>
#include <vector>
using namespace std;

int pArr[9] = {
    0,
};
bool check[9] = {
    false,
};

void permutation(int depth, int r, int n)
{
  if (depth == r)
  {
    for (int i = 0; i < r; i++)
      cout << pArr[i] << " ";
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++)
  {
    if (!check[i])
    {
      check[i] = true;
      pArr[depth] = i;
      permutation(depth + 1, r, n);
      check[i] = false;
    }
  }
}
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;

  permutation(0, M, N);
  return 0;
}