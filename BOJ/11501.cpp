#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 거꾸로 간다

long long solution(vector<long long> stok)
{
  long long ret = 0;
  while (stok.size() > 0)
  {
    int stokMaxIndex = max_element(stok.begin(), stok.end()) - stok.begin();
    long long stokMax = stok[stokMaxIndex];
    for (int i = 0; i <= stokMaxIndex; i++)
    {
      ret += stokMax - stok[0];
      stok.erase(stok.begin());
    }
  }

  return ret;
}

int main()
{
  int T;
  cin >> T;
  vector<int> answer;
  for (int i = 0; i < T; i++)
  {
    vector<long long> stok;
    int N;
    cin >> N;
    for (int j = 0; j < N; j++)
    {
      int tmp;
      cin >> tmp;
      stok.push_back(tmp);
    }
    answer.push_back(solution(stok));
  }

  for (int i = 0; i < T; i++)
    cout << answer[i] << '\n';

  return 0;
}