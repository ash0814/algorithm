#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;
	queue<string> words[101];
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		string w = "";
		for (int idx = 0; idx < str.length(); idx++) {
			if (str[idx] == ' ') {
				words[i].push(w);
				w = "";
			} else {
				w += str[idx];
			}
		}
		if (w.length() > 0)
			words[i].push(w);
	}

	string L;
	getline(cin, L);

	string word = "";
	for (int i = 0; i < L.length(); i++) {
		if (L[i] == ' ') {
			bool flag = false;
			for (int qi = 0; qi < N; qi++) {
				if (words[qi].front() == word) {
					words[qi].pop();
					flag = true;
				}
			}
			word = "";
			if (!flag) {
				cout << "Impossible";
				return 0;
			}
		} else {
			word += L[i];
		}
	}

	if (word.length() > 0) {
		bool flag = false;
		for (int qi = 0; qi < N; qi++) {
			if (words[qi].front() == word) {
				words[qi].pop();
				flag = true;
			}
		}
		if (!flag) {
			cout << "Impossible";
			return 0;
		}
	}
    
    for (int i = 0; i < N; i++)
	{
		if (words[i].size() > 0) {
			cout << "Impossible";
			return 0;
		}
	}

	cout << "Possible";
	return 0;
}