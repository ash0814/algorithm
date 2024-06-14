#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	vector<int> list;
	int numbers[100001] = {0, };
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		list.push_back(num);
	}

	int res = -1;
	int e = 0;

	for (int s = 0; s < N; s++) {
		while (e < N && numbers[list[e]] < K) {
			numbers[list[e]]++;
			e++;
		}

		if (e - s > res)
			res = e - s;
		if (e == N)
			break;
		numbers[list[s]]--;
	}
	printf("%d", res);
}