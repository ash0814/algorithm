#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int pascal[31][31] = {0, };

	pascal[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		pascal[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
		}
	}

	cout << pascal[n - 1][k - 1];
}