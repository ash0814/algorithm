#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int res = 0;
  stack<int> st;
  for (int i = 0; i <= N; i++) {
    int x, y;
    if (i == N)
      y = 0;
    else
      cin >> x >> y;
    while (!st.empty() && st.top() >= y) {
      if (st.top() != y)
        res++;
      st.pop();
    }
    st.push(y);
  }
  cout << res;
}