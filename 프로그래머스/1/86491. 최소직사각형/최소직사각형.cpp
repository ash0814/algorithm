#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    priority_queue<int> w;
    priority_queue<int> h;
    for (auto card : sizes) {
        int a = card[0];
        int b = card[1];
        if (a > b) {
            w.push(a);
            h.push(b);
        } else {
            w.push(b);
            h.push(a);
        }
    }
    answer = w.top() * h.top();
    return answer;
}