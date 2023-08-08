#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int main(void) {
  int t, w;
  cin >> t >> w;

  vector<int> jadu;

  for (int i = 0; i < t; i++)
  {
    int tree;
    cin >> tree;
    jadu.push_back(tree);
  }

  int current = 1;
  vector<int> get_jadu;
  int cnt = 0;
  int j = 0;
  for (int i = 0; i < jadu.size(); i++)
  {
    cout << "jadu[" << i << "] = " << jadu[i] << ", cnt: " << cnt << endl;
    if (jadu[i] == current)
    {
      // cnt++;
      get_jadu[j]++;
    }
    else
    {
      j++;
      current = jadu[i];
      get_jadu.push_back(1);
    }
  }

  print_vector(get_jadu);
  
  cout << "=============" << endl;
  int answer = 0;
  cout << get_jadu.size() << ", " << w << endl;
  if (get_jadu.size() <= w)
  {
    for (int i = 0; i < get_jadu.size(); i++)
      answer += get_jadu[i];
  } else {
  for (int i = 0; i < get_jadu.size() - w; i++)
  {
    int tmp = 0;
    int j = 0;
    while (j <= w) {
      tmp += get_jadu[i + j];
      j++;
    }
    if (tmp > answer)
      answer = tmp;
  }
  }
  cout << "answer : " << answer << endl;
  return 0;
}