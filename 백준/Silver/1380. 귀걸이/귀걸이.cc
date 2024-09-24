#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int senario = 1;

	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<string> list;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			string str;
			getline(cin, str);
			list.push_back(str);
		}

		set<int> s;
		for (int i = 0; i < 2 * n - 1; i++) {
			int a;
			char c;
			cin >> a >> c;
			if (s.find(a) == s.end()) {
				s.insert(a);
			} else {
				s.erase(s.find(a));
			}
		}
		int idx = *s.begin();
		cout << senario << " " << list[idx - 1] << '\n';
		senario++;
	}
	return 0;
}