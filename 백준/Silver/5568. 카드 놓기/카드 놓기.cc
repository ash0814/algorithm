#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> numbers;
set<int> res;
bool visited[10] = {0, };
int N, k;

void solution(int size, string s)
{
	if (size == k) {
		res.insert(stoi(s));
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		string tmp = s;
		tmp += to_string(numbers[i]);
		solution(size+1, tmp);
		visited[i] = false;
	}
}

int main()
{
	cin >> N >> k;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		numbers.push_back(n);
	}

	solution(0, "");
	cout << res.size();
}