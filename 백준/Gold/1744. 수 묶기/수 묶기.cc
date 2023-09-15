#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<long long> posList;
  vector<long long> negList;
  vector<long long> sumList;
  int isZero = 0;
  int one = 0;
  int m_one = 0;
  long long res = 0;

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int num;
    cin >> num;
    if (num > 1)
      posList.push_back(num);
    else if (num < 0)
      negList.push_back(num);
    else if (num == 0)
      isZero++;
    else if (num == 1)
      one++;
  }
  sumList.push_back(one);

  sort(posList.begin(), posList.end());
  sort(negList.begin(), negList.end());

  while (negList.size() > 1)
  {
    sumList.push_back(negList[0] * negList[1]);
    negList.erase(negList.begin(), negList.begin() + 2);
  }

  if (!negList.empty())
  {
    if (isZero > 0)
      sumList.push_back(0);
    else
      sumList.push_back(negList[0]);
  }

  if (posList.size() % 2 != 0)
  {
    sumList.push_back(posList[0]);
    posList.erase(posList.begin());
  }
  for (int i = 0; i < posList.size(); i += 2)
  {
    sumList.push_back(posList[i] * posList[i + 1]);
  }

  for (int i = 0; i < sumList.size(); i++)
    res += sumList[i];
  cout << res << endl;
  return 0;
}