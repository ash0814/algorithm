#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

//r1 = root((x1 - x)^2 + (y1 - y)^2);

int solution(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double dis = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	double bigr = max(r1, r2);
	double smallr = min(r1, r2);

	if (dis < bigr) {
		if (dis + smallr == bigr)
			return 1;
		else if (dis + smallr < bigr)
			return 0;
		else
			return 2;
	} else if (r1 + r2 > dis)
		return 2;
	else if (r1 + r2 == dis)
		return 1;
	else
		return 0;
}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		int x1, y1, x2, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 ==y2) {
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
			cout << solution(x1, y1, r1, x2, y2, r2) << '\n';
	}
}