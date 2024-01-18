#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int res = 0;
	N = 1000 - N;
	res += N / 500;
	N %= 500;
	res += N / 100;
	N %= 100;
	res += N / 50;
	N %= 50;
	res += N / 10;
	N %= 10;
	res += N / 5;
	N %= 5;
	res += N;

	cout << res;
}