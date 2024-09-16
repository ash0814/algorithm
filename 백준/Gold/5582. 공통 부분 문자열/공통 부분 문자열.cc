#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int graph[4001][4001] = {0, };
	int res = 0;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				if (i > 0 && j > 0) {
					graph[i][j] = graph[i-1][j-1] + 1;
				} else {
					graph[i][j] = 1;
				}
			}
			if (graph[i][j] > res)
				res = graph[i][j];
		}
	}

	cout << res;

	return 0;
}