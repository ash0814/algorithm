#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s1, s2;
	int alpha[26] = {0, };
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		alpha[s1[i] - 'a']++;
	}

	int res = s1.length();

	for (int i = 0; i < s2.length(); i++) {
		int c = s2[i] - 'a';
		if (alpha[c] > 0) {
			alpha[c]--;
			res--;
			continue;
		} else {
			res++;
		}
	}

	cout << res;
}