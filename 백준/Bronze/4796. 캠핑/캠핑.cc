#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int L, P, V;
	unsigned int caseNumber = 0;
	while (1) {
		cin >> L >> P >> V;
		if (L==0 && P==0 && V==0)
			return 0;
		unsigned int day = (V / P) * L + min((V % P), L);
		caseNumber++;
		cout << "Case " << caseNumber << ": " << day << '\n';
	}
}