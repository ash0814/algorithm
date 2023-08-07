#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int is_possible(int children, int value, vector<int> colorCount) {
  int check = 0;

  for (int i = 0; i < colorCount.size(); i++)
  {
    while (colorCount[i] > value) {
      check++;
      colorCount[i] -= value;
    }
    check++;
    if (check > children)
      return 0;
  }
  return 1;
}

int main(void) {
  int children;
  int colors;
  vector<int> colorCount;
  cin >> children;
  cin >> colors;

  for (int i = 0; i < colors; i++) {
    int n;
    cin >> n;
    colorCount.push_back(n);
  }

  int start, end, mid;
  start = *max_element(colorCount.begin(), colorCount.end());
  end = 0;

  while (end + 1 < start) {
    mid = (start + end) / 2;
    if (is_possible(children, mid, colorCount))
      start = mid;
    else
      end = mid;
  }
  cout << start << endl;
  return 0;
}