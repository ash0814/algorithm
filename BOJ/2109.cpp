#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  int N;
  cin >> N;
  map<int, int> mp;

  for (int i = 0; i < N; i++)
  {
    int p, d;
    cin >> p >> d;

    if (mp.find(d)->second >= p)
    {
      continue;
    }
    else
    {
      mp.erase(d);
      mp.insert({d, p});
    }
  }

  int ret = 0;
  for (auto iter : mp)
  {
    ret += iter.second;
  }

  cout << ret << endl;
  return 0;
}