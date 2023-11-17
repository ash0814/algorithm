#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> list;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        list.push_back(num);
        sum += num;
    }
    sort(list.begin(), list.end());
    cout << sum / 5 << endl;
    cout << list[2] << endl;
    return 0;
}