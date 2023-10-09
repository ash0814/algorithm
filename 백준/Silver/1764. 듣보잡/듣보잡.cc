#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
  int N, M;
  vector<string> answer;
  map<string, int> m;
  cin >> N >> M;
  while (N--)
  {
    string name;
    cin >> name;
    m[name] = 1;
  }
  while (M--)
  {
    string n;
    cin >> n;
    if (m[n] == 1)
      answer.push_back(n);
  }
  cout << answer.size() << endl;
  sort(answer.begin(), answer.end());
  for (auto name : answer)
  {
    cout << name << endl;
  }
}