#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> list;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}

	deque<int> answer;
	for (int i = N; i > 0; i--)
	{
		if (list[i-1] == 0) {
			answer.push_front(i);
		} else {
			answer.insert(answer.begin() + list[i-1], i);
		}
	}

	for (auto n : answer)
		cout << n << " ";
}