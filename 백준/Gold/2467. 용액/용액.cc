#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

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

	int start = 0;
	int end = N - 1;
	int cur = abs(list[start] + list[end]);

	int resA = list[start];
	int resB = list[end];

	while (start < end) {
		int liquid = list[start] + list[end];

		if (abs(liquid) <= cur) {
			cur = abs(liquid);
			resA = list[start];
			resB = list[end];
		}

		if (liquid < 0) {
			start++;
		} else if (liquid > 0) {
			end--;
		} else {
			break;
		}
	}

	cout << resA << " " << resB;
}