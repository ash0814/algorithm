#include <iostream>
#include <map>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	map<int, int> A;
	map<int, int> B;

	while(a--)
	{
		int num;
		cin >> num;
		A.insert({num, 1});
	}
	while (b--)
	{
		int num;
		cin >> num;
		B.insert({num, 1});
	}


	int res = 0;
	for (auto n : A)
	{
		int num = n.first;
		if (B[num] != 1)
			res++;
	}

	for (auto n : B)
	{
		if (A[n.first] != 1)
			res++;
	}

	cout << res << '\n';
}