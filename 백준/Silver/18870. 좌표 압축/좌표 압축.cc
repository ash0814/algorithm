#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  int N;
  cin >> N;
  map<int, int> m;
  vector<int> list;
  vector<int> list_sort;
  for (int i = 0; i < N; i++)
  {
    int num;
    cin >> num;
    list.push_back(num);
    list_sort.push_back(num);
  }
  sort(list_sort.begin(), list_sort.end());
  for (auto n : list_sort)
  {
    m.insert({n, m.size()});
  }
  for (auto n : list)
  {
    cout << m[n] << " ";
  }
}