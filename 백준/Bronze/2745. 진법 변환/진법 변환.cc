#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	string N;
	int B;
	long long res = 0;
	cin >> N >> B;
	string bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	reverse(N.begin(), N.end());
	for (int i = 0; i < N.length(); i++)
	{
		size_t idx = bstr.find(N[i]);
		res += idx * pow(B, i);
	}
	cout << res << '\n';
}