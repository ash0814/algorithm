#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	int cnt = 0;

	for (int i = 0; i < m; i++)
	{
		int ioi = 0;
		if (str[i] == 'I')
		{
			while(str[i+1] == 'O' && str[i+2] == 'I') {
				ioi++;
				if (ioi == n) {
					cnt++;
					ioi--;
				}
				i+= 2;
			}
			ioi = 0;
		}
	}
	cout << cnt;
}