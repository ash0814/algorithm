#include <iostream>

using namespace std;

// 풀이 몰라서 찾아봄
// A와 B의 최대공약수 구한 후, 그 수만큼 1 출력하기

long long gcd(long long a, long long b) {
	long long r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	long long A, B;

	cin >> A >> B;

	long long len = gcd(A, B);
	for (int i = 0; i < len; i++)
		cout << 1;
	cout << endl;
}