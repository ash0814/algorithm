#include <iostream>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long sum = 0;
	long long idx = 0;
	while (sum < N)
	{
		idx++;
		sum += idx;
	}
	if (sum == N)
		cout << idx;
	else
		cout << idx-1;
	return 0;
}