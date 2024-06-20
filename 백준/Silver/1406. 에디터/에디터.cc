#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int N;
    string str = "";
    stack<char> left;
    stack<char> right;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
        left.push(str[i]);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char cmd, c;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            left.push(c);
        }
    }
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
		
    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}