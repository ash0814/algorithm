#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	long long N, M;
	cin >> N >> M;

	vector<long long> tree;
	while (N--) {
		int num;
		cin >> num;
		tree.push_back(num);
	}

	sort(tree.begin(), tree.end());

	long long low;
	long long high = tree[tree.size() -1];

	long long result;

	while (low <= high)
	{
		long long sum = 0;
		long long mid = (low + high) / 2;

		for (auto n : tree) {
			if (n > mid)
                sum += n - mid;
		}

		if (sum >= M) {
			result = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}

	}
	cout << result;

	return 0;
}