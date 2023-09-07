#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(vector<long long> stok)
{
  long long ret = 0;
  long long now = -1;
  for (int i = stok.size() - 1; i >= 0; i--)
  {
    if (now < stok[i])
    {
      now = stok[i];
    }
    else
    {
      ret += now - stok[i];
    }
  }

  return ret;
}

int main()
{
  int T;
  cin >> T;
  vector<long long> answer;
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