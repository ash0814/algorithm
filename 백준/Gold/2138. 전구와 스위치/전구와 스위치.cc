#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> st, ed, tmp;
int cnt = 0;
int answer = 987654321;

void click(vector<int> &v, int idx)
{
	v[idx] = v[idx] == 0 ? 1 : 0;
	if (idx != 0) {
		v[idx - 1] = v[idx - 1] == 0 ? 1 : 0;
	}
	if (idx != N - 1) {
		v[idx + 1] = v[idx + 1] == 0 ? 1 : 0;
	}
}

bool solution(vector<int> &v)
{
	for (int i = 1; i < N; i++) {
		if(v[i-1] != ed[i-1]) {
			click(v, i);
			cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (v[i] != ed[i])
			return false;
	}
	return true;;
}

int main()
{
	cin >> N;
	string input;
	cin >> input;
	for (int i = 0; i < N; i++)
		st.push_back(input[i] - '0');
	cin >> input;
	for (int i = 0; i < N; i++)
		ed.push_back(input[i] - '0');
	tmp = st;

	click(st, 0);
	cnt++;

	bool flag = true;
	if (solution(st)) {
		answer = min(answer, cnt);
	} else {
		flag = false;
	}
	cnt = 0;
	if (solution(tmp)) {
		answer = min(answer, cnt);
		flag = true;
	}

	if (flag == false)
		cout << -1;
	else
		cout << answer;
}