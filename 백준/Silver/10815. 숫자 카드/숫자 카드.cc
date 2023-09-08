#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
  int N, M;
  set<int> st;
  scanf("%d", &N);

  while (N--)
  {
    int num;
    scanf("%d", &num);
    st.insert(num);
  }

  scanf("%d", &M);
  while (M--)
  {
    int num;
    scanf("%d", &num);
    if (st.find(num) != st.end())
      printf("1 ");
    else
      printf("0 ");
  }
}