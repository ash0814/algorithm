#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  map<int, string> user;
  int N;
  cin >> N;
  for (int id = 1; id <= N; id++)
  {
    int age;
    string name;
    cin >> age >> name;
    pq.push({age, id});
    user.insert({id, name});
  }
  while (!pq.empty())
  {
    cout << pq.top().first << " " << user[pq.top().second] << '\n';
    pq.pop();
  }
}