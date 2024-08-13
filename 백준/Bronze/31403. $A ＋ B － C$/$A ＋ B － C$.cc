#include <iostream>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int bcnt = 0;
	int tmp = B;
	while (tmp > 0) {
		tmp /= 10;
		bcnt++;
	}

	cout << (A + B) - C << "\n";

	while (bcnt--) {
		A *= 10;
	}

	cout << (A + B) - C << endl;
}