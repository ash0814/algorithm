#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int list[10] = {0,};
int arr[10] = {0, };
int visited[10] = {0, };

void perm(int cnt, int idx)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	int x = 0;
	for (int i = idx; i < N; i++)
	{
		if (!visited[i] && list[i] != x) {
			arr[cnt] = list[i];
			x = arr[cnt];
			visited[i] = true;
			perm(cnt + 1, i);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> list[i];
	sort(list, list + N);

	perm(0, 0);
}