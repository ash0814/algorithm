#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T;
  cin >> T;
  vector<int> trophy;
  while (T--)
  {
    int t;
    cin >> t;
    trophy.push_back(t);
  }

  int left = 0;
  int right = 0;
  int max = -1;

  for (auto t : trophy)
  {
    if (max < t)
    {
      left++;
      max = t;
    }
  }
  max = -1;
  for (int i = trophy.size() - 1; i >= 0; i--)
  {
    if (max < trophy[i])
    {
      right++;
      max = trophy[i];
    }
  }

  cout << left << endl;
  cout << right << endl;

  return 0;
}