#include <iostream>

using namespace std;

int main()
{
	int A, B, N;
	cin >> A >> B >> N;

	int res = 0;

	if (A % B == 0) {
		cout << 0;
		return 0;
	}

	if (A > B) {
		A %= B;
	}

	for (int i = 0; i < N; i++) {
		A *= 10;
		res = (int)(A / B);
		A %= B;
	}
	cout << res;
}