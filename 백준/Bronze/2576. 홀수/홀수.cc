#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int i = 7;
	vector<int> list;
	int sum = 0;
	while (i--)
	{
		int num;
		cin >> num;

		if (num % 2) {
			sum += num;
			list.push_back(num);
		}
	}
	sort(list.begin(), list.end());

	if (sum == 0) {
		cout << -1;
	} else {
		cout << sum << '\n' << list[0];
	}
}