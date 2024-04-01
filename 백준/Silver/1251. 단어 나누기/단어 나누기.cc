#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	priority_queue<string, vector<string>, greater<string>> pq;
	string str;
	cin >> str;

	string a = "";
	for (int i = 0; i < str.length() - 2; i++) {
		a = str[i] + a;
		string b = "";
		for (int j = i + 1; j < str.length() - 1; j++) {
			b = str[j] + b;
			string c;
			for (int k = j + 1; k < str.length(); k++) {
				c = str[k] + c;
			}
			string newStr = a + b + c;
			pq.push(newStr);
		}
	}

	cout << pq.top() << endl;
}