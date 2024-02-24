#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;
		map<int, int> one;
		vector<int> two;

		while(N--)
		{
			int num;
			cin >> num;
			one[num] = 1;
		}

		int M;
		cin >> M;
		while (M--)
		{
			int num;
			cin >> num;
			two.push_back(num);
		}

		for (auto m: two)
		{
			if (one[m] == 1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}