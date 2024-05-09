#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long N) {
  if (N == 0 || N == 1)
	  return false;
  for (int i = 2; i <= sqrt(N); i++) {
    if (N % i == 0)
		return false;
  }
  return true;
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		long long n;
		cin >> n;
		while (isPrime(n) == false)
			n++;
		cout << n << "\n";
	}
}