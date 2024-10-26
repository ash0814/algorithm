#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> input;
int K;
vector<int> tree[10];

void solution(int start, int end, int depth)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	tree[depth].push_back(input[mid]);
	solution(start, mid, depth + 1);
	solution(mid + 1, end, depth + 1);
}

int main()
{
	// 중위순회
	cin >> K;
	int len = pow(2, K) - 1;
	for (int i = 0; i < len; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}

	solution(0, len, 0);

	for (int i = 0; i < K; i++) {
		for (auto n : tree[i])
			cout << n << " ";
		cout << endl;
	}
}