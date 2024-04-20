#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int list[10] = {0,};
int arr[10] = {0, };
int visited[10] = {0, };

void perm(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == false) {
			visited[i] = true;
			arr[cnt] = list[i];
			perm(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list, list + N);

	perm(0);
}