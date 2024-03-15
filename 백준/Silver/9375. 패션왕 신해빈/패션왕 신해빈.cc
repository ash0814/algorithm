#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		map<string, int> closet;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string name, type;
			cin >> name >> type;

			if (closet[type])
				closet[type]++;
			else
				closet[type] = 1;
		}

		int res = 1;
		for (auto k : closet)
		{
			res *= k.second + 1;
		}
		cout << res - 1 << '\n';
	}
}