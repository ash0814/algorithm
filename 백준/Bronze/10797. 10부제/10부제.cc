#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int res = 0;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        if (num == N)
            res++;
    }
    cout << res;
}