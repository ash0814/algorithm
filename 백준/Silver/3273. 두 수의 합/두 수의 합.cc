#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n;

	vector<int> list;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}
	cin >> x;

	sort(list.begin(), list.end());

	int i = 0;
	int j = list.size() - 1;
	int cnt = 0;

	while (i < j) {
		if (list[i] + list[j] == x) {
			cnt++;
			i++;
			j--;
		} else if (list[i] + list[j] < x) {
			i++;
		} else if (list[i] + list[j] > x) {
			j--;
		}
	}
	cout << cnt;
}