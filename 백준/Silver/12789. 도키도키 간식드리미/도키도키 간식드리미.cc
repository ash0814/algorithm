#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	queue<int> input;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		input.push(num);
	}

	stack<int> ready;

	int idx = 1;

	while (!input.empty()) {
		if (input.front() == idx) {
			idx++;
			input.pop();
		} else if (!ready.empty() && ready.top() == idx) {
			idx++;
			ready.pop();
		}else {
			ready.push(input.front());
			input.pop();
		}
	}

	bool res = false;
	while (!ready.empty()) {
		if (ready.top() == idx) {
			idx++;
			ready.pop();
		} else {
			break;
		}
	}
	if (ready.empty())
		res = true;

	if (res)
		cout << "Nice\n";
	else
		cout << "Sad\n";
}