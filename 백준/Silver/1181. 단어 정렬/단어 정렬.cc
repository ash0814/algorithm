#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
  int N;
  cin >> N;
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> list;
  while (N--)
  {
    string str;
    cin >> str;
    list.push({str.length(), str});
  }

  queue<string> res;
  while (!list.empty())
  {
    if ((res.size() > 0 && res.back() != list.top().second) || res.size() == 0)
      res.push(list.top().second);
    list.pop();
  }
    
  while (!res.empty())
  {
    cout << res.front() << endl;
    res.pop();
  }
  return 0;
}