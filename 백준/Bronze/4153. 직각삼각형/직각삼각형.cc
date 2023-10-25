#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int a, b, c;
  vector<int> line;
  cin >> a >> b >> c;
  while (!(a == 0 && b == 0 && c == 0))
  {
    line.push_back(a);
    line.push_back(b);
    line.push_back(c);
    sort(line.begin(), line.end());
    if (line[0] * line[0] + line[1] * line[1] == line[2] * line[2])
      cout << "right" << endl;
    else
      cout << "wrong" << endl;
    line.clear();
    cin >> a >> b >> c;
  }
}