#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

	int N, M;
	int list[100001] = {0, };
	int sumList[100001] = {0, };
	cin >> N >> M;

	for (int i = 1; i <= N; i++){
		cin >> list[i];
		sumList[i] = sumList[i-1] + list[i];
	}

	while (M--)
	{
		int i,j;
		cin >> i >> j;
		cout << sumList[j] - sumList[i - 1] << '\n';
	}
}