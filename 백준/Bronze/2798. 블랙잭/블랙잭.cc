#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> cards;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    cards.push_back(num);
  }
  sort(cards.begin(), cards.end());
  int sum = 0;
  int max = -1;
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = i + 1; j < n - 1; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        sum = cards[i] + cards[j] + cards[k];
        if (max < sum && sum <= m)
          max = sum;
      }
    }
  }
  cout << max << endl;
  return 0;
}