#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, num;
	cin >> N >> num;

	int graph[1000][1000] = {0, };

	int cur = N * N;
	int depth = 1;
	while (cur > 1) {
		for (int i = depth-1; i < N - depth; i++) {
			graph[i][depth - 1] = cur--;
		}
		for (int j = depth-1; j < N - depth; j++) {
			graph[N - depth][j] = cur--;
		}
		for (int i = N - depth; i > depth-1; i--) {
			graph[i][N - depth] = cur--;
		}
		for (int j = N - depth; j > depth - 1; j--) {
			graph[depth-1][j] = cur--;
		}
		depth++;
	}
	graph[N/2][N/2] = 1;

	int reti, retj;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
			if (graph[i][j] == num) {
				reti = i;
				retj = j;
			}
		}
		cout << '\n';
	}
	cout << reti + 1 << " " << retj + 1;
}