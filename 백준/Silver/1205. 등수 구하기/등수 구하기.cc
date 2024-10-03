#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, S, P;
	int rank[100];

	cin >> N >> S >> P;

	for (int i = 0; i < N; i++) {
		cin >> rank[i];
	}
	int cnt = 0;
	int my_rank = 1;
	for (int i = 0; i < N; i++) {
			if (S < rank[i])
				my_rank++;
			else if (S == rank[i])
				my_rank = my_rank;
			else
				break;
			cnt++;
	}


	if (cnt == P)
		my_rank = -1;
	if (N == 0)
		my_rank = 1;
	cout << my_rank;

	return 0;
}