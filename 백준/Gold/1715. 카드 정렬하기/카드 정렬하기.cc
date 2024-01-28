#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// 풀이 참고 : 현재 존재하는 묶음 중, 가장 작은 것 두개 고르기

using namespace std;

int main()
{
	int N;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		pq.push(n);
	}

	vector<int> sumList;

	while (pq.size() > 1)
	{
		int s = pq.top();
		pq.pop();
		s += pq.top();
		pq.pop();
		sumList.push_back(s);
		pq.push(s);
	}
	int res = 0;

	for (auto n : sumList) {
		res += n;
	}

	cout << res << endl;
}