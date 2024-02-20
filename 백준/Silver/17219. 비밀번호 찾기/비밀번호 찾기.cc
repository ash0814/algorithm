#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, string> memo;
	while (N--)
	{
		string address, pwd;
		cin >> address >> pwd;
		memo.insert({address, pwd});
	}
	while (M--)
	{
		string add;
		cin >> add;
		cout << memo[add] << '\n';
	}
}