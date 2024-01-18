#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;
	vector<char> list;
	int rope = 0;
	int res = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ')') {
			if (input[i-1] == '(')
			{
				res += rope;
			} else {
				res++;
				rope--;
			}
		} else {
			if (input[i+1] != ')')
			{
				rope++;
			}
		}
	}

	cout << res << endl;
}