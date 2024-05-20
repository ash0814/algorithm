#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> student;
	long long len[21] = {0, };
	long long ans = 0;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		int nLen = name.length();
		len[nLen]++;
		student.push(nLen);
		if (student.size() > K + 1) {
			len[student.front()]--;
			student.pop();
		}
		ans += len[nLen] - 1;
	}
	cout << ans;
}