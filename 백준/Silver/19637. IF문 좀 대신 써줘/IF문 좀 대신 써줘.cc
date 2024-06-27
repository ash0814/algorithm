#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M;
int power[100001];
string title[100001];

int bsearch(int p)
{
	int mid;
	int start = 0;
	int end = N - 1;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (p <= power[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}

	if (p > power[mid])
		return mid + 1;
	return mid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> title[i] >> power[i];
	}

	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;

		cout << title[bsearch(input)] << "\n";
	}
	return 0;
}