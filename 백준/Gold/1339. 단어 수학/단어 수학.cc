#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	map<char, int> mp;
	vector<string> input;
	for (int i = 0; i < N; i++) {
		string alpha;
		cin >> alpha;
		input.push_back(alpha);

		int alen = alpha.size();
		for (int i = 1; i <= alen; i++) {
			char c = alpha[alen - i];
			int digit = pow(10, i);
			mp.insert({c, 0});
			mp[c] += digit;
		}
	}

	priority_queue<pair<int, char>> pq;
	for (auto m : mp)
		pq.push({m.second, m.first});

	int num = 9;
	map<char, int> matching;
	while (!pq.empty())
	{
		char c = pq.top().second;
		pq.pop();
		if (matching.find(c) == matching.end()) {
			matching.insert({c, num});
			num--;
		}
	}

	int sum = 0;
	for (auto str : input) {
		int number = 0;
		for (int i = 0; i < str.length(); i++) {
			number = number * 10 + (matching[str[i]]);
		}
		sum += number;
	}

	cout << sum;
}