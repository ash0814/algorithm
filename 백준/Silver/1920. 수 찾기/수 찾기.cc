#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  unordered_map<long, int> A;
  cin >> N;
  while (N--)
  {
    long a;
    cin >> a;
    A.insert({a, 0});
  }

  cin >> M;
  while (M--)
  {
    long num;
    cin >> num;
    if (A.find(num) != A.end())
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
  return 0;
}