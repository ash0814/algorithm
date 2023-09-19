#include <iostream>
using namespace std;
int main()
{
  int list[9];
  for (int i = 0; i < 8; i++)
    cin >> list[i];
  if (list[0] == 1 && list[1] == 2 && list[2] == 3 && list[3] == 4 && list[4] == 5 && list[5] == 6 && list[6] == 7 && list[7] == 8)
    cout << "ascending" << endl;
  else if (list[7] == 1 && list[6] == 2 && list[5] == 3 && list[4] == 4 && list[3] == 5 && list[2] == 6 && list[1] == 7 && list[0] == 8)
    cout << "descending" << endl;
  else
    cout << "mixed" << endl;
  return 0;
}