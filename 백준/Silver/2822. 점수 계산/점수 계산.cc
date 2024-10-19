#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	map<int, int, greater<int>> score;
	for (int i = 1; i<= 8; i++){
		int num;
		cin >> num;
		score.insert({num, i});
	}

	set<int> n;
	int sum = 0;
	int idx = 0;
	for (auto s : score) {
		if (idx >= 5)
			break;
		sum += s.first;
		n.insert(s.second);
		idx++;
	}

	cout << sum << '\n';
	for (auto nn : n) {
		cout << nn << " ";
	}
	return 0;
}