#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int A, P;
	cin >> A >> P;
	vector<int> list;

	list.push_back(A);
	int cur = A;
	while (1)
	{
		int sum = 0;
		while (cur > 0)
		{
			sum += pow(cur % 10, P);
			cur /= 10;
		}
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] == sum)
			{
				cout << i << endl;
				return 0;
			}
		}
		list.push_back(sum);
		cur = sum;
	}
}