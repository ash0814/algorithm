#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	string S;
	cin >> S;
	int q;
	cin >> q;

	int alphabet[26][200001] = {0, };
	alphabet[S[0] - 'a'][0] = 1;
	for (int i = 1; i < S.length(); i++) {
		for (int j = 0; j < 26; j++) {
			alphabet[j][i] = alphabet[j][i - 1];
		}
		alphabet[S[i] - 'a'][i]++;
	}

	while (q--)
	{
		char a;
		int l, r;
		cin >> a >> l >> r;
		int aIdx = a - 'a';
		if (l == 0)
			cout << alphabet[aIdx][r] << '\n';
		else
			cout << alphabet[aIdx][r] - alphabet[aIdx][l - 1] << '\n';
	}
	return 0;
}