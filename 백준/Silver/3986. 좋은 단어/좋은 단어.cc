#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int ans = 0;
	int N;
	cin >> N;

	while (N--)
	{
		string str;
		cin >> str;
		stack<char> st;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'A')
			{
				if (st.size() > 0 && st.top() == 'A')
					st.pop();
				else
					st.push('A');
			} else {
				if (st.size() > 0 && st.top() == 'B')
					st.pop();
				else
					st.push('B');
			}
		}
		if (st.size() == 0)
			ans++;
	}

	cout << ans << endl;
}