#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> list;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}

	sort(list.begin(), list.end());

	int start = 0;
	int end = N - 1;

	int resA = list[start];
	int resB = list[end];
	int cur = abs(list[start] + list[end]);
	while (start < end) {
		int sum = list[start] + list[end];

		if (cur > abs(sum)) {
			resA = list[start];
			resB = list[end];
			cur = abs(sum);
		}
		if (sum < 0) {
			start++;
		} else if (sum > 0) {
			end--;
		} else {
			break;
		}
	}

	cout << resA << " " << resB;
}