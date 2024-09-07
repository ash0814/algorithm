#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

void solution(int s, int e)
{
	if (s >= e) {
		return ;
	}
	int root = list[s];
	int idx = s + 1;

	while (idx < e) {
		if (root < list[idx])
			break;
		idx++;
	}

	solution(s + 1, idx);
	solution(idx, e);
	cout << root << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	while (cin >> num)
	{
		list.push_back(num);
	}

	solution(0, list.size());
}