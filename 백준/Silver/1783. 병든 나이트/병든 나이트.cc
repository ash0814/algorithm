#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int res = 0;
    cin >> N >> M;

    if (N == 1)
        res = 1;
    else if (N == 2)
        res = min(4, (M + 1) / 2);
    else if (M < 7)
        res = 4 > M ? M : 4;
    else 
        res = M - 2;
    
    cout << res << endl;
}