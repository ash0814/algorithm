#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int graph[51][51] = {0, };
	int dist[51][51] = {0, };

	for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dist[i][j] = 987654321;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] == 'Y') {
				graph[i][j] = 1;
				dist[i][j] = 1;
			} else {
				graph[i][j] = 0;
			}
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
			}
		}
	}


	int ans = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (dist[i][j] <= 2)
				cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;

}