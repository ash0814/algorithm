#include <iostream>
#include <cmath>

using namespace std;

void move(int n, int s, int e)
{
	cout << s << " " << e << '\n';
}

void hanoi(int n, int start, int end, int sub)
{
	if (n == 1) {
		move(1, start, end);
		return ;
	}

	hanoi(n - 1, start, sub, end);
	move(n, start, end);
	hanoi(n-1, sub, end, start);
}

int main()
{
	int N;
	cin >> N;

	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, 1, 3, 2);

}