#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	priority_queue<int, vector<int>, greater<int>> list;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int weight;
		cin >> weight;
		list.push(weight);
	}
	int max = 0;
	while (!list.empty())
	{
		int tmp = list.top() * list.size();
		if (tmp > max)
			max = tmp;
		list.pop();
	}
	cout << max;
}