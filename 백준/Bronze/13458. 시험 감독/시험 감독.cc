#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> tester;
	while (N--)
	{
		int num;
		scanf("%d", &num);
		tester.push_back(num);
	}
	int B, C;
	scanf("%d %d", &B, &C);
	long long cnt = 0;
	for (auto n : tester) {
		n -= B;
		cnt++;
		if (n > 0) {
			cnt = n % C == 0 ? cnt + n / C : cnt + n / C + 1;
		}
	}

	printf("%lld", cnt);

}