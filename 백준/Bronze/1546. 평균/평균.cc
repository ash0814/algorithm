#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T;
  cin >> T;
  vector<float> score;
  int max = -1;
  for (int i = 0; i < T; i++)
  {
    int s;
    cin >> s;
    score.push_back(s);
    max = s > max ? s : max;
  }
  float sum = 0;
  for (int i = 0; i < score.size(); i++)
  {
    score[i] = score[i] / max * 100;
    sum += score[i];
  }

  cout << sum / T << endl;
  return 0;
}