#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int N;
	cin >> N;

	vector<long long> dis;
	vector<long long> price;
	int len = 0;
	for (int i = 0; i < N - 1; i++) {
		int d;
		cin >> d;
		len += d;
		dis.push_back(d);
	}
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		price.push_back(p);
	}

	long long cur = price[0];
	long long res = 0;
	for (int i = 0; i < N - 1; i++) {
		if (price[i] < cur)
			cur = price[i];
		res += cur * dis[i];
	}
	cout << res;
}