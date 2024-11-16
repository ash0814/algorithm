#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
		map<int, int> test;
		priority_queue<int, vector<int>, greater<int>> min_queue;
		priority_queue<int, vector<int>, less<int>> max_queue;

        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            char cmd;
            int num;
            cin >> cmd >> num;

            if (cmd == 'I')
            {
                min_queue.push(num);
                max_queue.push(num);
                if (test.count(num) == 0)
                    test[num] = 1;
                else
                    test[num]++;
            }
            if (cmd == 'D')
            {
                if (num == 1)
                {

                    while (!max_queue.empty() && test[max_queue.top()] == 0)
                        max_queue.pop();
                    if (max_queue.empty() == 1)
                        continue;
                    test[max_queue.top()]--;
                    max_queue.pop();
                }
                if (num == -1)
                {

                    while (!min_queue.empty() && test[min_queue.top()] == 0)
                        min_queue.pop();
                    if (min_queue.empty() == 1)
                        continue;
                    test[min_queue.top()]--;
                    min_queue.pop();
                }
            }
        }

        while (!max_queue.empty() && test[max_queue.top()] == 0)
            max_queue.pop();
        while (!min_queue.empty() && test[min_queue.top()] == 0)
            min_queue.pop();
        if (max_queue.empty() == 1)
            cout << "EMPTY\n";
        else
            cout << max_queue.top() << " " << min_queue.top() << "\n";
    }
}