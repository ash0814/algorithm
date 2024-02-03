#include <iostream>
#include <queue>

using namespace std;

int main()
{
	string numbers;
	priority_queue<char> pq;
	cin >> numbers;

	for (int i = 0; i < numbers.length(); i++)
	{
		pq.push(numbers[i]);
	}

	while(!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}

}