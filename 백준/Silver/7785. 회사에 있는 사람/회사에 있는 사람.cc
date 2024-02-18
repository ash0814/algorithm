#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	map<string, int, greater<string>> list;
	while (N--)
	{
		string name, e;
		cin >> name >> e;
		if (list[name] == 1)
			list[name] = 0;
		else
			list[name] = 1;
	}

	for (auto m : list)
	{
		if (m.second == 1)
			cout << m.first << '\n';
	}
}