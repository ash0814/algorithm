#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string S, T;

void solution(string s, string t)
{
	if (s.size() == t.size()) {
		if (s == t) {
			cout << 1;
			exit(0);
		}
		return;
	}

	if (t[t.size()-1] == 'A') {
		string tmp = t;
		tmp.pop_back();
		solution(s, tmp);
	}

	if (t[0] == 'B') {
		string tmp = t;
		reverse(tmp.begin(), tmp.end());
		tmp.pop_back();
		solution(s, tmp);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S >> T;

	solution(S, T);
	cout << 0;
}