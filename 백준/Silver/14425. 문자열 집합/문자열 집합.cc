#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, int> s;
	while(N--)
	{
		string str;
		cin >> str;
		s.insert({str, 1});
	}
	int cnt = 0;
	while (M--)
	{
		string str;
		cin >> str;
		if (s[str] == 1)
			cnt++;
	}
	cout << cnt;
}