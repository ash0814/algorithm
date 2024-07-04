#include <iostream>

using namespace std;

char cookie[1001][1001];
int N;

int main()
{
  cin >> N;

  for (int i = 1; i <= N; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= N; j++) {
      cookie[i][j] = str[j - 1];
    }
  }

  int heart[2];
  int arm[2] = {0, 0};;
  int waist = 0;
  int leg[2] = {0, 0};

  bool head = false;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (!head && cookie[i][j] == '*') {
        head = true;
        heart[0] = i + 1;
        heart[1] = j;
      } else if (i == heart[0] && j < heart[1] && cookie[i][j] == '*') {
        arm[0]++;
      } else if (i == heart[0] && j > heart[1] && cookie[i][j] == '*') {
        arm[1]++;
      } else if (head && i > heart[0] && j == heart[1] && cookie[i][j] == '*') {
        waist++;
      } else if (i > heart[0] && j == heart[1] - 1 && cookie[i][j] == '*') {
          leg[0]++;
      } else if (i > heart[0] && j == heart[1] + 1 && cookie[i][j] == '*') {
          leg[1]++;
      }
    }
  }

  cout << heart[0] << " " << heart[1] << endl;
  cout << arm[0] << " " << arm[1] << " " << waist << " " << leg[0] << " " << leg[1] << " "<< endl;
}