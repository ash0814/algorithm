#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<long long, vector<long long>, greater<long long>> list;

	int N, K;
	cin >> N >> K;

	while (N--)
	{
		long long n;
		cin >> n;
		list.push(n);
	}

	while (--K)
	{
		list.pop();
	}
	cout << list.top();
}