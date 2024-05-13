#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int N, S;
	cin >> N >> S;

	vector<int> list;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}

	int start = 0;
	int end = 0;
	set<int> res;

	sum += list[start];

	bool flag = false;
	while (1)
	{
		if (sum >= S) {
			res.insert(end - start + 1);
			sum -= list[start];
			start++;
			flag = true;
		} else {
			if (end < N-1) {
				end++;
				sum += list[end];
			} else {
				break;
			}
		}

		if (start == N) {
			break;
		}
		if (start == 0 && end == N) {
			break;
		}
	}

	if (flag)
		cout << *(res.begin());
	else
		cout << 0;
}