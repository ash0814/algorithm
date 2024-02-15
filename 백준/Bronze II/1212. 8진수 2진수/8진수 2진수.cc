#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string input;
	cin >> input;
	string answer = "";
	for (int i = input.length() - 1; i >= 0; i--)
	{
		int n = input[i]- '0';
		string nn = "";
		while(n > 0)
		{
			if (n % 2 == 1)
				nn += '1';
			else
				nn += '0';
			n /= 2;
		}
		while (nn.length() < 3)
			nn += "0";

		answer += nn;
	}
	reverse(answer.begin(), answer.end());
	if (answer.find('1') != string::npos)
		cout << answer.substr(answer.find('1')) << endl;
	else
		cout << 0 << endl;
}