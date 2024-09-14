#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;

	vector<int> numList;
	while (num > 0) {
		numList.push_back(num % 10);
		num /= 10;
	}

	int cnt = 0;
	set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	vector<set<int>> sv;
	for (auto n : numList) {
		if (sv.size() > 0) {
			bool found = false;
			for (auto &cs : sv) {
				if (cs.find(n) != cs.end()) {
					cs.erase(cs.find(n));
					found = true;
					break;
				} else if (n == 6 && cs.find(9) != cs.end()) {
					cs.erase(cs.find(9));
					found = true;
					break;
				} else if (n == 9 && cs.find(6) != cs.end()) {
					cs.erase(cs.find(6));
					found = true;
					break;
				}
			}
			if (!found) {
				set<int> ns = s;
				ns.erase(ns.find(n));
				sv.push_back(ns);
			}
		} else {
			set<int> ns = s;
			ns.erase(ns.find(n));
			sv.push_back(ns);
		}
	}

	cout << sv.size();
}