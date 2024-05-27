#include <iostream>
#include <vector>

using namespace std;

vector<int> connect[100001];
vector<int> childs[100001];
int vsize[100001] = {0, };

void makeTree(int currentNode, int parent) {
	for (auto node : connect[currentNode]) {
		if (node != parent) {
			childs[currentNode].push_back(node);
			// set Node's parent to currentNode
			makeTree(node, currentNode);
		}
	}
}

void countSubtreeNodes(int currentNode) {
	vsize[currentNode] = 1;
	for (auto node : childs[currentNode]) {
		countSubtreeNodes(node);
		vsize[currentNode] += vsize[node];
	}
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N, R, Q;
	cin >> N >> R >> Q;

	for (int i = 1; i < N; i++) {
		int U, V;
		cin >> U >> V;
		connect[U].push_back(V);
		connect[V].push_back(U);
	}

	makeTree(R, -1);
	countSubtreeNodes(R);

	for (int i = 0; i < Q; i++) {
		int r;
		cin >> r;

		cout << vsize[r] << '\n';
	}
}