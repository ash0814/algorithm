#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> list;

	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		list.push_back(n);
	}
	sort(list.begin(), list.end());

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++) {
			int sum = 0;
			for (int k = 0; k < 9; k++)
			{
				if (k != i && k != j)
					sum += list[k];
			}
			if (sum == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
						cout << list[k] << '\n';
				}
                return 0;
			}
		}
	}
}