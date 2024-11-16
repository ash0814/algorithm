#include <string>
#include <vector>

using namespace std;

int timeToInt(string input)
{
    int m = (input[0] - '0') * 10 + (input[1] - '0');
    int s = (input[3] - '0') * 10 + (input[4] - '0');
    return m * 60 + s;
}

string intToTime(int input) {
    int m = input / 60;
    int s = input % 60;
    
    string ret = "";
    ret += (char)((m / 10) + '0');
    ret += (char)((m % 10) + '0');
    ret += ':';
    ret += (char)((s / 10) + '0');
    ret += (char)((s % 10) + '0');
    return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int v_len = timeToInt(video_len);
    int s_len = timeToInt(op_start);
    int e_len = timeToInt(op_end);
    int cur = timeToInt(pos);
    
    for (auto cmd : commands) {
        if (s_len <= cur && cur <= e_len)
            cur = e_len;
        if (cmd == "next") {
            cur = cur + 10 > v_len ? v_len : cur + 10;
        } else if (cmd == "prev") {
            cur = cur - 10 < 0 ? 0 : cur - 10;
        }
    }
    if (s_len <= cur && cur <= e_len)
        cur = e_len;
    
    answer = intToTime(cur);
    
    return answer;
}