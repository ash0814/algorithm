#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> A;
  vector<int> B;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int num;
    cin >> num;
    A.push_back(num);
  }
  for (int i = 0; i < N; i++)
  {
    int num;
    cin >> num;
    B.push_back(num);
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int s = 0;
  for (int i = 0; i < N; i++)
  {
    s += B[i] * A[N - i - 1];
  }
  cout << s << '\n';
  return 0;
}