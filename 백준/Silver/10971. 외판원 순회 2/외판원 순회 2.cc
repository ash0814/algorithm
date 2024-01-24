#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int n;
	int graph[11][11] = {0,};
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	vector<int> cities;
	for (int i = 0; i < n; i++)
		cities.push_back(i);
	int min_path = INT_MAX;
	while(next_permutation(cities.begin(), cities.end()))
	{
		int sum = 0;
		int is_impossible = false;
		for (int g = 0; g < n-1; g++)
		{
			int i = cities[g];
			int j = cities[g+1];
			if (graph[i][j] == 0)
			{
				is_impossible = true;
				break;
			}
			sum += graph[i][j];
		}
		int i = cities[n-1];
		int j = cities[0];
		if (graph[i][j] == 0)
			is_impossible = true;
		sum += graph[i][j];
		if (is_impossible == false) {
			min_path = min(sum, min_path);
		}
	}
	cout << min_path << endl;
}