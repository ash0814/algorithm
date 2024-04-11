#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int calculate(vector<int> list, vector<char> oper)
{
	int ans = list[0];
	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == 'a') {
			ans += list[i+1];
		} else if (oper[i] == 'b') {
			ans -= list[i+1];
		} else if (oper[i] == 'c') {
			ans *= list[i+1];
		} else {
			ans /= list[i+1];
		}
	}
	return ans;
}

int main()
{
	int N;
	cin >> N;
	vector<int> list;
	while (N--)
	{
		int num;
		cin >> num;
		list.push_back(num);
	}

	vector<char> oper;

	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		while (num--) {
			oper.push_back('a' + i);
		}
	}

	set<int> results;

	do {
		results.insert(calculate(list, oper));
	} while (next_permutation(oper.begin(), oper.end()));


	cout << *(results.rbegin()) << "\n" << *(results.begin());
}