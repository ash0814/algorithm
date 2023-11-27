#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long N, T, P;
  vector<long long> shirts;
  cin >> N;
  for (int i = 0; i < 6; i++)
  {
    long long n;
    cin >> n;
    shirts.push_back(n);
  }
  cin >> T >> P;
  int shirts_t = 0;
  for (auto t : shirts)
  {
    shirts_t += ceil(t / (double)T);
  }
  cout << shirts_t << '\n'
       << N / P << " " << N % P << '\n';
}