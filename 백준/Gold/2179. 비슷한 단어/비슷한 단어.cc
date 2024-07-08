#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<string> origin;
	set<string> sorted;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		origin.push_back(s);
	}

	string res_s, res_t;
	int cur = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int len = min(origin[i].size(), origin[j].size());
			int cnt = 0;
			for (int idx = 0; idx < len; idx++) {
				if (origin[i][idx] != origin[j][idx])
					break;
				else {
					cnt++;
				}
			}

			if (cnt > cur) {
				res_s = origin[i];
				res_t = origin[j];
				cur = cnt;
			}
		}
	}

	cout << res_s << '\n';
	cout << res_t << '\n';
}