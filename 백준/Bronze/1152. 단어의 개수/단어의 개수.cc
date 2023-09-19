#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
  string str, tmp;
  getline(cin, str);
  vector<string> result;
  stringstream ss(str);
  while (getline(ss, tmp, ' '))
  {
    if (tmp.length() > 0)
      result.push_back(tmp);
  }
  cout << result.size() << endl;
  return 0;
}