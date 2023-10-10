#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool check(long l) {
    if (l < 5 && l != 2) return true;
    if ((l - 2) % 5 == 0) return false;

    return check(l / 5);
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    for (long long i = l - 1; i < r; i++) {
        // cout << i << endl;
        if (check(i)) answer++;
    }
    return answer;
}
