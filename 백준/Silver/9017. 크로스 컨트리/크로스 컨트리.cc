#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

void solution()
{
	int N;
	cin >> N;

	vector<int> list;
	map<int, int> pcnt;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		list.push_back(num);
		if (pcnt.find(num) == pcnt.end())
			pcnt.insert({num, 1});
		else
			pcnt[num]++;
	}

	map<int, int> score;
	for (auto n : pcnt) {
		if (n.second < 6)
			list.erase(remove(list.begin(), list.end(), n.first), list.end());
		else {
			score.insert({n.first, 0});
		}
	}

	vector<int> remain;
	int scnt[201] = {0, };
	for (int i = 0; i < list.size(); i++) {
		if (scnt[list[i]] < 4) {
			score[list[i]] += i + 1;
		} else {
			remain.push_back(list[i]);
		}
		scnt[list[i]]++;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (auto n : score) {
		pq.push({n.second, n.first});
	}

	vector<pair<int, int>> same;
	same.push_back(pq.top());
	pq.pop();

	while (pq.top().first == same[same.size()-1].first && !pq.empty()) {
		same.push_back(pq.top());
		pq.pop();
	}

	if (same.size() == 1) {
		cout << same[0].second << "\n";
	} else {
		for (auto n : remain) {
			int flag = false;
			for (auto s : same) {
				if (n == s.second) {
					cout << n << "\n";
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		solution();
	}

	return 0;
}