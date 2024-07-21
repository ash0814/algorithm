#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	stack<int> right, left;
	cin >> N;
	int buildings[100001];
	int near[100001];
	int cnt[100001];

	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i];
		near[i] = 1000000;
		cnt[i] = 0;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (right.empty())
			right.push(i);
		else
		{
			while (!right.empty())
			{
				if (buildings[i] < buildings[right.top()])
				{
					near[i] = right.top();
					cnt[i] = right.size();
					break;
				}
				else
					right.pop();
			}
			right.push(i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (left.empty())
			left.push(i);
		else
		{
			while (!left.empty())
			{
				if (buildings[i] < buildings[left.top()])
				{
					if (abs(near[i] - i) >= abs(left.top() - i))
						near[i] = left.top();
					cnt[i] += left.size();
					break;
				}
				else
					left.pop();
			}
			left.push(i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << cnt[i];
		if (cnt[i] != 0)
			cout << " " << near[i] + 1;
		cout << "\n";
	}
	return 0;
}