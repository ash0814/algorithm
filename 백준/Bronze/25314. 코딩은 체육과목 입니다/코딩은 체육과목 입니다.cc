#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N)
	{
		cout << "long ";
		N -= 4;
	}
	cout << "int" << endl;
	return 0;
}