#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int G;
	bool flag = false;
	cin >> G;

	long long x = 1;
	long long y = 1;

	while (1)
	{
		if (x * x - y * y == G) {
			flag = true;
			cout << x << '\n';
		}

		if (x - y == 1 && x*x - y*y > G) // 가장 인접한 제곱수끼리의 차가 G보다 크면 끝
			break;
		if (x*x - y*y > G) // G보다 값이 크면 뺄 값(이전 몸무게:y)를 추가
			y++;
		else // 아닐땐 현재 몸무게(x) 추가
			x++;
	}

	if (flag == false)
		cout << -1;
}