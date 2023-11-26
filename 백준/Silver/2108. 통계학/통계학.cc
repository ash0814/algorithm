#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> list;
  map<int, int> m;
  int sum = 0;
  while (N--)
  {
    int num;
    cin >> num;
    if (m.find(num) == m.end())
      m.insert({num, 1});
    else
      m[num]++;
    sum += num;
    list.push_back(num);
  }
  sort(list.begin(), list.end());
  pair<int, int> p = {0, -1};
  vector<pair<int, int>> most_list;
  for (auto n : m)
  {
    if (p.second < n.second)
    {
      most_list.clear();
      p.first = n.first;
      p.second = n.second;
      most_list.push_back(n);
    }
    else if (p.second == n.second)
    {
      most_list.push_back(n);
    }
  }

  int avg = round((double)sum / (double)list.size());
  int center = list[round((double)list.size() / 2) - 1];
  int range = list[list.size() - 1] - list[0];
  int most;
  if (most_list.size() < 2)
    most = most_list[0].first;
  else
    most = most_list[1].first;
  cout << avg << '\n'
       << center << '\n'
       << most << '\n'
       << range << '\n';
}