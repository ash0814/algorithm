#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	while (1) {
		cin >> N;
		if (cin.eof())
			return 0;

		long long l = 1;
		int cnt = 1;
		while (l % N != 0) {
			l = (l * 10 + 1) % N;
			cnt++;
		}
		cout << cnt << '\n';
	}
}