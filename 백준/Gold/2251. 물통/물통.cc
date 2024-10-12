#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, C;
	set<int> res;
	cin >> A >> B >> C;

	int total = C;

	queue<pair<int, int>> q;
	q.push({0, 0});

	bool visited[201][201] = {0, };
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int c = total - (a + b);
		if (a == 0) {
			res.insert(c);
		}
		visited[a][b] = true;
		q.pop();
		// cout << a << ", " << b << endl;

		if (a > 0) {
			if (b < B) {
				int na, nb;
				if (b + a < B) {
					nb = b + a;
					na = 0;
				} else {
					nb = B;
					na = (a + b) - B;
				}
				if (!visited[na][nb])
					q.push({na, nb});
			}
			if (c < C) {
				int na, nc;
				if (a + c  < C) {
					na = 0;
					nc = a + c;
				} else {
					na = (a + c) - C;
					nc = C;
				}
				int nb = total - (na + nc);
				if (!visited[na][nb])
					q.push({na, nb});
			}
		}
		if (b > 0) {
			if (a < A) {
				int na, nb;
				if (a + b < A) {
					nb = 0;
					na = a + b;
				} else {
					na = A;
					nb = (a + b) - A;
				}
				if (!visited[na][nb])
					q.push({na, nb});
			}
			if (c < C) {
				int nb, nc;
				if (b + c < C) {
					nb = 0;
					nc = b + c;
				} else {
					nb = (b + c) - C;
					nc = C;
				}
				int na = total - (nb + nc);
				if (!visited[na][nb])
					q.push({na, nb});
			}
		}
		if (c > 0) {
			if (a < A) {
				int na, nc;
				if (a + c < A) {
					nc = 0;
					na = a + c;
				} else {
					na = A;
					nc = (a + c) - A;
				}
				int nb = total - (na + nc);
				if (!visited[na][nb])
					q.push({na, nb});
			}
			if (b < B) { // C -> B
				int nb, nc;
				if (b + c < B) {
					nc = 0;
					nb = b + c;
				} else {
					nb = B;
					nc = (b+c) - B;
				}
				int na = total - (nb + nc);
				if (!visited[na][nb])
					q.push({na, nb});
			}
		}
	}

	for (auto r : res) {
		cout << r << " ";
	}
}
