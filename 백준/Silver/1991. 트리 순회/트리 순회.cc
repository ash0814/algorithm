#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;
pair<char, char> tree[26];


void preorder(char c)
{
	if (c != '.') {
		cout << c;
		preorder(tree[c-'A'].first);
		preorder(tree[c-'A'].second);
	}
}

void inorder(char c)
{
	if (c != '.') {
		inorder(tree[c-'A'].first);
		cout << c;
		inorder(tree[c-'A'].second);
	}
}

void postorder(char c)
{
	if (c != '.')
	{
		postorder(tree[c-'A'].first);
		postorder(tree[c-'A'].second);
		cout << c;
	}
}

int main()
{
	cin >> N;

	while (N--) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[(a-'A')].first = b;
		tree[(a-'A')].second = c;
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
}