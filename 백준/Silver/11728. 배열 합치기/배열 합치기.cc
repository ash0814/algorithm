#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int N, M;
	scanf("%d %d", &N, &M);
	while (N--) {
		long long num;
		scanf("%lld", &num);
		pq.push(num);
	}
	while (M--) {
		long long num;
		scanf("%lld", &num);
		pq.push(num);
	}

	while (!pq.empty()) {
		printf("%lld " , pq.top());
		pq.pop();
	}
}