#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<int, int> s;
  for (int i = 1; i <= 20; i++)
	  s.insert({i, 0});
  int M;
  cin >> M;
  while (M--)
  {
    string cmd;
    cin >> cmd;
	int x;
    if (cmd == "add") {
		cin >> x;
		s[x] = 1;
    } else if (cmd == "remove") {
		cin >> x;
		s[x] = 0;;
	} else if (cmd == "check") {
		cin >> x;
		if (s[x] == 1)
			cout << 1 << "\n";
		else
			cout << 0 << '\n';
	} else if (cmd == "toggle") {
		cin >> x;
		s[x] = s[x] == 1 ? 0 : 1;
	} else if (cmd == "all") {
		for (int i = 1; i <= 20; i++)
			s[i] = 1;
	} else if (cmd == "empty") {
		for (int i = 1; i <= 20; i++)
			s[i] = 0;
	}
  }
}