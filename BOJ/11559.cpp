#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

char field[13][7];
char visited[13][7];

void printField() {
  cout << "======field======" << endl;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++)
      cout << field[i][j] << " ";
    cout << endl;
  }
}

bool isBomb(int a, int b) 
{
  queue<pair<int, int>> qu;

  qu.push({a, b});
};

void bomb(){};

void go_down() {};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> field[i][j];
    }
  }

  printField();

  int time = 0;
  while(1) {

    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if (field[i][j] != '.' && visited[i][j] != 1)
          isBomb(i, j);
      }
    }

    bomb();
    go_down();
    time++;
  }

  return 0;
}