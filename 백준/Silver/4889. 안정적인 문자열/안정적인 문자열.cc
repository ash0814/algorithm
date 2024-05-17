#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string s;
	int T = 0;
	while (1)
	{
		cin >> s;
		if (s[0] == '-')
			break;
		cout << ++T << ". ";

		stack<char> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '{')
				st.push(s[i]);
			else {
				if (st.empty() || st.top() != '{') {
					st.push(s[i]);
				} else {
					st.pop();
				}
			}
		}
		int cnt = 0;
		while (!st.empty())
		{
			char c = st.top();
			st.pop();

			if (c == st.top())
				cnt++;
			else
				cnt += 2;
			st.pop();
		}
		cout << cnt << '\n';
	}
}