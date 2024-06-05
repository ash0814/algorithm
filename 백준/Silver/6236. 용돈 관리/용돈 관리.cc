#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int start = 1;
	int end = 0;
	vector<int> list;
	while (N--) {
		int money;
		cin >> money;
		list.push_back(money);
		end += money;
	}

	int res;
	int total;
	while (start <= end) {
		int mid = (start + end) / 2;
		int total = mid;

		int cnt = 1;
		bool flag = true;

		for (auto n : list) {
			int day_money = n;
			if (day_money > mid) {
				flag = false;
				break;
			}
			if (day_money > total) {
				total = mid;
				cnt++;
			}
			total -= day_money;
		}

		if (!flag || cnt > M) {
			start = mid + 1;
		} else {
			res = mid;
			end = mid - 1;
		}
	}
	cout << res;
}