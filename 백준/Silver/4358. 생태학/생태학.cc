#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
  map<string, int> trees;
  string str;
  int total = 0;
  while (getline(cin, str))
  {
    if (trees.find(str) == trees.end())
      trees.insert({str, 1});
    else
      trees[str]++;
    total++;
  }

  for (auto tree : trees)
  {
    double res = ((double)tree.second / (double)total) * 100;

    cout << fixed;
    cout.precision(4);
    cout << tree.first << " " << res << endl;
  }

  return 0;
}