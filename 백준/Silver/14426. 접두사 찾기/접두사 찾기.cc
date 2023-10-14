#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<string> dictionary;

bool isPrefix(string comp)
{
  int l = 0;
  int r = dictionary.size() - 1;

  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (comp < dictionary[mid])
      r = mid - 1;
    else if (comp > dictionary[mid])
      l = mid + 1;
    if (dictionary[mid].substr(0, comp.length()) == comp)
      return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  int answer = 0;
  cin >> N >> M;
  while (N--)
  {
    string str;
    cin >> str;
    dictionary.push_back(str);
  }

  sort(dictionary.begin(), dictionary.end());

  while (M--)
  {
    string comp;
    cin >> comp;
    if (isPrefix(comp))
      answer++;
  }

  cout << answer << endl;

  return 0;
}