#include <string>
#include <vector>
#include <iostream>

using namespace std;

string intToChar(int num, int n) {
    string ret = "";
    for (int i = 0; i < n; i++) {
        char c = num % 2 + '0';
        ret = c + ret;
        num /= 2;
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        string map1 = intToChar(arr1[i], n);
        string map2 = intToChar(arr2[i], n);
        string line = "";
        for (int j = 0; j < n; j++) {
            if (map1[j] == '0' && map2[j] == '0')
                line += ' ';
            else
                line += '#';
        }
        answer.push_back(line);
    }
    return answer;
}