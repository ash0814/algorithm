#include <iostream>
using namespace std;

int main(void)
{
	int K;
	cin >> K;
	pair<int, int> p[12];

	for (int i = 0; i < 6; i++)
	{
		int dir, len;
		cin >> dir >> len;
		p[i] = {dir, len};
		p[i + 6] = {dir, len};
	}

	int w, h, mw, mh;
	for (int i = 3; i < 12; i++)
	{
		if (p[i].first == p[i - 2].first && p[i - 1].first == p[i - 3].first)
		{
			w = p[i + 1].second;
			h = p[i + 2].second;
			mw = p[i - 1].second;
			mh = p[i - 2].second;
			break;
		}
	}

	cout << (w * h - mw * mh) * K << endl;
	return 0;
}