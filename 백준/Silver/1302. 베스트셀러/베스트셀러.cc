#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	map<string, int> list;
	int maxNum = -1;
	while (N--)
	{
		string book;
		cin >> book;

		if (list.find(book) == list.end())
			list.insert({book, 1});
		else
			list[book]++;

		if (list[book] > maxNum)
			maxNum = list[book];
	}

	set<string> res;
	for (auto n : list)
	{
		if (n.second == maxNum)
			res.insert(n.first);
	}

	cout << *(res.begin());
}