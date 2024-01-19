#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	vector<int> list;
	int res = 0;

	cin >> N >> M;
	while(N--)
	{
		int num;
		cin >> num;
		list.push_back(num);
	}

	for (int idx = 0; idx < list.size(); idx++)
	{
		int sum = 0;
		for (int i = idx; i < list.size() && sum < M; i++) {
			sum += list[i];
		}
		if (sum == M)
			res++;
	}
	cout << res << endl;
	return 0;
}