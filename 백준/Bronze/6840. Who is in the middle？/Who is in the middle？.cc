#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int list[3];
    cin >> list[0] >> list[1] >> list[2];
    sort(list, list + 3);
    cout << list[1];
}