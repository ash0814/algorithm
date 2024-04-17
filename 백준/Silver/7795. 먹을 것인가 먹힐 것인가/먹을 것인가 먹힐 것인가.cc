#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<int> A;
		vector<int> B;

		while (N--) {
			int num;
			cin >> num;
			A.push_back(num);
		}
		while (M--) {
			int num;
			cin >> num;
			B.push_back(num);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int cnt = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = B.size() - 1; j >= 0; j--) {
				if (A[i] > B[j]) {
					cnt += j + 1;
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
}