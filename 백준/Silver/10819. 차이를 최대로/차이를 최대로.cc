#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int get_max(vector<int> cur)
{
	int sum = 0;
	for (int i = 0; i < cur.size() - 1; i++)
	{
		sum += abs(cur[i]-cur[i+1]);
	}

	return sum;
}

int main()
{
	int N;
	vector<int> list;
	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		list.push_back(n);
	}

	int max = 0;
	sort(list.begin(), list.end());
	while (next_permutation(list.begin(), list.end())){
		vector<int> cur;
		for(int i: list){
            cur.push_back(i);
		}

		int cur_max = get_max(cur);
		max = max > cur_max ? max : cur_max;
	}

	cout << max << endl;

	return 0;
}