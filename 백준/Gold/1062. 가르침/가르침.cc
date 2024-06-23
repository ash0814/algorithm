#include <iostream>
#include <vector>

using namespace std;

int N, K;
bool knowAlpha[26] = {false, };
int answer = 0;
vector<string> leftedStr;

bool canRead(string str)
{
	for (int i = 0; i < str.length(); i++) {
		if (knowAlpha[str[i]-'a'] == false)
			return false;
	}
	return true;
}

void dfs(int idx, int cnt)
{
	if (cnt == K) {
		int readCnt = 0;
		for (auto s : leftedStr) {
			if (canRead(s))
				readCnt++;
		}
		if (readCnt > answer)
			answer = readCnt;
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (!knowAlpha[i]) {
			knowAlpha[i] = true;
			dfs(i, cnt + 1);
			knowAlpha[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;


	knowAlpha['a' - 'a'] = true;
	knowAlpha['t' - 'a'] = true;
	knowAlpha['n' - 'a'] = true;
	knowAlpha['i' - 'a'] = true;
	knowAlpha['c' - 'a'] = true;

	int readCnt = 0;

	int add = 0;
	for (int i = 0; i < N; i++) {
		string input, mid;
		cin >> input;
		mid = input.substr(4, input.length() - 8);
		if (canRead(mid))
			add++;
		else
			leftedStr.push_back(mid);
	}

	if (K < 5) {
		cout << 0;
		return 0;
	}
	K -= 5;
	// unknown alphabet 중, K 개를 골라서 true로 했을 때 res가 가장 높은 것
	// backtraking 으로 구하기
	// dfs?

	dfs(0, 0);
	cout << answer + add;
}