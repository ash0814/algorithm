#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string str;

	cin >> str;

	stack<char> st;
	int tmp = 1;
	int answer = 0;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if (c == '(') {
			tmp *= 2;
			st.push(c);
		} else if (c == '[') {
			tmp *= 3;
			st.push(c);
		} else {
			if (c == ')') {
				if (st.size() == 0 || st.top() != '(') {
					cout << 0;
					return 0;
				} else {
					if (i > 0 && str[i-1] == '(')
						answer += tmp;
					tmp /= 2;
					st.pop();
				}
			} else if (c == ']') {
				if (st.size() == 0 || st.top() != '[') {
					cout << 0;
					return 0;
				} else {
					if (i > 0 && str[i-1] == '[')
						answer += tmp;
					tmp /= 3;
					st.pop();
				}
			}
		}
	}
	if (st.size() > 0)
	    cout << 0;
    else
	    cout << answer;
}