#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int L, C;
vector<char> charactor;
set<string> pwd;
string str;
bool visited[16] = {false, };

bool isVow(char c)
{
	if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
		return true;
	return false;
}

void dfs(int idx)
{
	if (str.length() == L) {
		int vow = 0;
		int con = 0;
		for (int i = 0; i < str.length(); i++) {
			if (isVow(str[i]))
				vow++;
			else
				con++;
		}
		if (vow >= 1 && con >= 2)
			pwd.insert(str);
	}

	for (int i = idx; i < C; i++) {
		if (!visited[i]) {
			visited[i] = true;
			str += charactor[i];
			dfs(i);
			visited[i] = false;
			str.pop_back();
		}
	}
}

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		charactor.push_back(c);
	}

	sort(charactor.begin(), charactor.end());

	dfs(0);

	for (auto s : pwd)
		cout << s << "\n";
}