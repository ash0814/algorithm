#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int lcnt=0;

	for (int i = 0; i < N; i++) {
		char seat;
		cin >> seat;
		if (seat == 'L')
			lcnt++;
	}

	cout << min(N, (N + 1 - (lcnt/2))) << endl;
}