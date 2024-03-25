#include <iostream>

using namespace std;

string makeP(int n)
{
	string res = "I";
	for (int i = 0; i < n; i++)
		res += "OI";
	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	int cnt = 0;

	string p = makeP(n);

	size_t found = str.find(p);
	string cut = str;
	while (found != string::npos)
	{
		cnt++;
		cut = cut.substr(found + 1);
		found = cut.find(p);
	}
	cout << cnt;
}