#include <iostream>
#include <queue>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--) {
    	string cmd;
		cin >> cmd;

		int n;
    	cin >> n;

		deque<int> dq;

		string input;
		cin >> input;

		int idx = 0;
		int num = 0;
		while (++idx < input.length() && dq.size() < n)
		{
			if (!('0' <= input[idx] && input[idx] <= '9')) {
				dq.push_back(num);
				num = 0;
				continue;
			}
			else {
				num = num * 10 + (input[idx] - '0');
			}
		}

		bool is_reverse = false;
		bool is_error = false;

		for (int i = 0; i < cmd.length(); i++)
		{
			if (cmd[i] == 'R') {
				is_reverse = is_reverse ? false : true;
			} else {
				if (dq.empty()) {
					is_error = true;
					break;
				} else {
					if (is_reverse == false) {
						dq.pop_front();
					} else {
						dq.pop_back();
					}
				}
			}
		}

		if (is_error)
			cout << "error\n";
		else {
			cout << "[";
			if (is_reverse == false) {
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}
			} else {
				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}