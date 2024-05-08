#include <iostream>

using namespace std;

const int MAX = 1025;
int graph[MAX][MAX] = {0, };
int sumGraph[MAX][MAX] = {0, };

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];

			sumGraph[i][j] = sumGraph[i-1][j] + sumGraph[i][j-1] - sumGraph[i-1][j-1] + graph[i][j];
		}
	}
	while (M--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sumGraph[x2][y2] - sumGraph[x2][y1-1] - sumGraph[x1-1][y2] + sumGraph[x1-1][y1-1] << '\n';
	}
}