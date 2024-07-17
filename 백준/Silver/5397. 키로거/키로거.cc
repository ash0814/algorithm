#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solution()
{
	string input;
	cin >> input;

	stack<char> left;
	stack<char> right;

	for (int i = 0; i < input.length(); i++) {
		char cmd = input[i];

		if (cmd == '<') {
			if (left.size() > 0) {
				right.push(left.top());
				left.pop();
			}
		} else if (cmd == '>') {
			if (right.size() > 0) {
				left.push(right.top());
				right.pop();
			}
		} else if (cmd == '-') {
			if (left.size() > 0)
				left.pop();
		} else {
			left.push(cmd);
		}
	}

	string res = "";
	while (!left.empty()) {
		res += left.top();
		left.pop();
	}
	reverse(res.begin(), res.end());
	while (!right.empty()) {
		res += right.top();
		right.pop();
	}
	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		solution();
	}
}