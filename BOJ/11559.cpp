#include <iostream>

using namespace std;

char field[12][6];

int main()
{
  for (int i = 0; i < 12; i++)
    for (int j = 0; j < 6; j++)
      cin >> field[i][j];
}