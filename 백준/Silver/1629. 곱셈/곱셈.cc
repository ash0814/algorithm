#include <iostream>

using namespace std;

long long a, b, c;
long long answer;

long long power(long long b)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a % c;

	answer = power(b / 2) % c;
	if (b % 2 == 0)
		return answer * answer % c;
	else
		return answer * answer % c * a % c;
}

int main()
{
	cin >> a >> b >> c;

	cout << power(b);
}