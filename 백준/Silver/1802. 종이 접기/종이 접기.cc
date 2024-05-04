#include <iostream>

using namespace std;

bool solution(string str, int i, int j)
{
	if (i >= j)
		return true;
	int left = i;
	int right = j;
	while (left < right) {
		if (str[left] == str[right])
			return false;
		left++;
		right--;
	}
	return solution(str, i, right - 1);
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		string str;
		cin >> str;

		if (str.length() == 1 || solution(str, 0, str.length() - 1))
			cout << "YES" << '\n';
		else
			cout << "NO" << "\n";
	}
}